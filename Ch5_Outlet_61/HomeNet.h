//MOTE ��ȣ 
//////////////////////////////////////////////////////////////////
#ifndef __HomeNet_H__
#define __HomeNet_H__
///////////////////////////////////////////////////////////////////

enum{
	F_EDGE=0,
	R_EDGE=1
};

enum{
	SENSOR_TIMER = 200
};

enum{
	RFID_TIMER	= 1000
};

enum{
	  MOTE_001_SEN_HUMAN_DETECT		= 1
	, MOTE_002_SEN_HUMAN_DETECT		= 2
	, MOTE_011_SEN_HUMAN_DOOR_DETECT 	= 11  //��ü ������ ����
	, MOTE_031_DEV_DOOR_LOCK		= 31  //�����
	, MOTE_041_DEV_CURTAIN_GAS		= 41  //���� Ŀư (open / close)
	, MOTE_061_DEV_RELAY_LIGHT_FAN		= 61  //���� , ȯǳ��
	, MOTE_062_DEV_RELAY_TV_REFREG_AIRCON 	= 62  //TV/�����/������
	, MOTE_101_SEN_GAS_DETECT		= 101 //���������
};

enum{
	AM_UBIHOUSE				=0x3e,
	AM_UBIHOUSE_IN				=0x3f,
	UBIHOUSE_GROUP				=0x27
};

// moteid-LENGTH-COMMANDTYPE-DATA[0..4]
//COMMANDTYPE
enum{
	COMM_GET	=	1,
	COMM_SET	=	2,//���� ����
	COMM_INT	=	3,//���� �޼���
};

enum{
	//GET DATA
	COMM_GET_BAT				=1,
	COMM_GET_TEMP				=2,
	COMM_GET_HUMI				=3,
	COMM_GET_CDS				=4,
	COMM_GET_ALL				=5,
	COMM_GET_DAY_DETECT			=6,
	COMM_GET_GAS_DETECT_STATUS		=7,
	COMM_GET_REFREG_RFID			=8
};

enum{
	//INTERRUPT DATA
	//ũ��Ƽ�� ���ͷ�Ʈ 
	COMM_INT_GAS_DETECT			=1,		//���� ����
	COMM_INT_GAS_CLEAR			=2,		//���� ����
	COMM_INT_MOTION_DETECT			=3,		//��ü����
	COMM_INT_BAT_LOW			=4,		//������ �ʵ� 2BYTE�� Bat�� ���� ������.
	COMM_INT_DAY_DETECT			=5,		//�� �� ����, ���� ������ ������ �� ���� ���� ������ ������.
	COMM_INT_RFID				=6,		//RFID �±� ����, ���� ������ ������ �±� ������ ������.
	COMM_INT_REED				=7,		//������ ����
	COMM_INT_DOOR_RFID			=8,
	COMM_INT_BELL				=10,			
	COMM_INT_SENSING_POWER_ON		=11,
	COMM_INT_SENSING_POWER_OFF  		=12
};

enum{
	//SET DATA
	//Moter Cotrl
	//�ٸ� ���Ϳ� ������ ���� �ʰ� �ش� ���͸� �����Ѵ�. 
	COMM_SET_MOTER_1S		=0x0,			//1�� ���� ����
	COMM_SET_MOTER_1N		=0x1,			//1�� ���� ������
	COMM_SET_MOTER_1R		=0x2,			//1�� ���� ������
	COMM_SET_MOTER_0S		=0x3,			//0�� ���� ����
	COMM_SET_MOTER_0N		=0x4,			//0�� ���� ������
	COMM_SET_MOTER_0R		=0x5,			//0�� ���� ������


	COMM_SET_MOTER_1S0S		=0x6,			//S=STOP, N=NORMAL, R= REVERSE  1�� ���� ���� 0�� ���� ����
	COMM_SET_MOTER_1S0N		=0x7,			// 0�� ��Ʈ 0�� ������ On/Off
	COMM_SET_MOTER_1N0S		=0x8,			//1�� ��Ʈ 1�� ������ On/Off
	COMM_SET_MOTER_1N0N		=0x9,			//2�� ��Ʈ ���⼳��(1=R 0=N)
	COMM_SET_MOTER_1S0R		=0xa,			//ex> 110 ���� �� 1������ On 0�� ���� Off 
	COMM_SET_MOTER_1R0S		=0xb,
	COMM_SET_MOTER_1R0R		=0xc			//user ������ 2Byte ms ������ �����簣 ���� 0xFFFF �϶��� ��� 
};


enum{
	//SET DATA
	//Relay Cotrl

	COMM_SET_RELAY_1D		=0xd,
	COMM_SET_RELAY_1C		=0xe,
	COMM_SET_RELAY_0D		=0xf,
	COMM_SET_RELAY_0C		=0x10,

	COMM_SET_RELAY_1D0D		=0x11,			//C=Connect D=Disconnect
	COMM_SET_RELAY_1D0C		=0x12,			//0�� ��Ʈ 0�� Relay On/Off
	COMM_SET_RELAY_1C0D		=0x13,			//1�� ��Ʈ 1�� Relay On/Off
	COMM_SET_RELAY_1C0C		=0x14,			//user ������ 2Byte ms ������ �����簣 ���� 0xFFFF �϶��� ��� 

};

enum{
	//DIMMER
	COMM_SET_DIMMER_DN		=0x15,
	COMM_SET_DIMMER_UP		=0x16,
};

enum{
	//�⺻ ���α׷� ��ɿܿ� Ư���ϰ� ����Ǵ� ��ɵ�
	COMM_SET_GAS_ON			=0x17,	
	COMM_SET_GAS_OFF		=0x18,
	COMM_SET_CURTAIN_OPEN	=0x19,		//open
	COMM_SET_CURTAIN_CLOSE	=0x1a,		//close
	COMM_SET_CURTAIN_STOP	=0x1b,
	COMM_SET_TV_ON			=0x1c,
	COMM_SET_TV_OFF			=0x1d,
	COMM_SET_AIRCON_ON		=0x1e,
	COMM_SET_AIRCON_OFF		=0x1f,
	COMM_SET_REFREG_ON		=0x20,
	COMM_SET_REFREG_OFF		=0x21

};

///////////////////////////////////
#define RELAY_OFF	0
#define RELAY_ON	1
#define NOT_CONTROL	2

#define GAS_ESC		0
#define GAS_NORMAL	1
///////////////////////////////////

typedef struct _user_header{
	uint8_t id;
	uint8_t cmd;
	uint8_t sub;
	uint8_t length;
}user_header_t;

typedef struct _user_packet{
	user_header_t uh;
	uint8_t data;
}user_packet_t;

#define SensorDataLen 10

typedef struct _sens_data{
	user_header_t uh;
	uint16_t photo;
	uint16_t temp;
	uint16_t humi;
	uint16_t infrared;
	uint16_t battery;
}sens_data_t;

enum {AM_HOMENET=0x09};

///////////////////////////////////////////////////////
#endif
///////////////////////////////////////////////////////

