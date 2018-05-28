/*============================================================================*/
/*									      */
/*                           Author : Jin Nam Seo			      */
/*                            {scs}@hanback.co.kr			      */
/*									      */
/*                      Copyright (c) HANBACK ELECTRONICS		      */
/*                             All rights reserved.			      */
/*									      */
/*                            http://www.hanback.com			      */
/*									      */
/******************************************************************************/

/******************************************************************************/
/*									      */
/*============================================================================*/
/* Permission to use, copy, modify, and distribute this software and its      */
/* documentation are reserved by above authors and Hanback electronics.	      */
/* The above copyright notice and authors must be described in this software. */
/*============================================================================*/
/*									      */
/******************************************************************************/

#define NORMAL	
#define ESC_GAS

module GasDetectorP {
  provides interface   GasDetector;
  
  uses interface HplAtm128Interrupt as Int;
  uses interface Timer<TMilli> as timer;	//������ ��������  ���� �ð����� ��Ʈ�� üũ�ؼ� �������� Ȯ��
  uses interface Timer<TMilli> as timer1;	//������ ������ �� ���� �ð����� �ߺ� ������ ���� Ÿ�̸� 
  uses interface Leds;
}
implementation
{
  
  uint16_t m_normalCheckTime;			//������ �� ������·� ���ƿԴ��� Ȯ���ϴ� Ÿ�̸� 
  uint16_t m_firedCheckTime;			//������ ������ ���� �������� �Ⱓ�� �ּ� �ð�
  
  task void sendSignal() {
    
	call timer1.startOneShot(m_firedCheckTime);
    	call timer.startPeriodic(m_normalCheckTime);
    	signal GasDetector.EscapeOfGas();

  }
  
  task void timerStop(){
	call timer1.stop();
	call timer.stop();
	
  }

  async event void Int.fired() {
	call Int.disable();
	call Int.clear();
	if(READ_BIT(PINE, 5)){
		call Int.enable();
		post timerStop();
		return ;		//���� ª�� �ð� ���� ����. �Ǿ���..  ����?
	}
	post sendSignal();
  }

  event void timer.fired() {
	if(READ_BIT(PINE, 5)){
		signal GasDetector.BecomeNormal();
		call timer.stop();
	}
  }
 
  event void timer1.fired() {
 
	if(!READ_BIT(PINE, 5)){		//�ּ� ���� ������ �����µ� ������ �������̸� �� �ñ׳�
  		post sendSignal();
	}
	else{
		call Int.enable();	//�ƴϸ� ���ͷ�Ʈ �ο��̺�
	}
	
  }

  command void GasDetector.Init(uint8_t edge,uint16_t nomalcheckTimer,uint16_t minGapTimer){
	call Int.edge(edge);
	m_normalCheckTime = nomalcheckTimer;
	m_firedCheckTime = minGapTimer;
  }

  command uint8_t GasDetector.WatchEscOfGas(){
	uint8_t now;
	call Int.clear();
	if(READ_BIT(PINE, 5)){
		call Int.enable();
		now = 1;
	}
	else{
		post sendSignal();
		now =0;
	}
	return now;
  }
}
