#pragma once
#include <string>
#include<vector>
using namespace std;

#define Kdataoffsetnum					1441
#define Kmeasurearea					0.01			//m*m
typedef short int						int16_t;
typedef int								int32_t;
typedef unsigned short int				uint16_t;
typedef unsigned int					uint32_t;

typedef struct
{
	int16_t PreviousLength;
	char PixName[14];
	uint32_t MainTime;
	double LineFrequency;
	float PlaneDistanceBackLeft;
	float PlaneDistanceBackRight;
	float PlaneDistanceFrontRight;
	int16_t MidPixel;
	int16_t GateA;
	int16_t GateB;
	float HorizontalScaleA;
	float HorizontalScaleB;
	float OpticalDistanceA;
	float OpticalDistanceB; 
	int16_t OEUNumber;
	int16_t Format;
	int16_t DataGeneration;
	int16_t DataRevision;
	int16_t Frt;
}MainHeaderStructure;

typedef struct
{
	int16_t PreviousLength;
	uint32_t TimeInfo;
	uint32_t LastSync;
	int16_t Spare0;
	int16_t Spare1;
	int16_t Spare2;
	int16_t Spare3;
	char Padding[4];
}QuartHeaderStructure;

typedef struct
{
	int16_t PreviousLength;
	double FirstLineSinceMidnight;
	uint16_t EquiVolDiameter;
	int16_t NumOfLinesInA;
	int16_t DiffOfLinesInBAndA;
	int16_t DiffLineCountersAtBottom;
	int16_t MinPixelNumberInA;
	int16_t MinPixelNumberINB;
	uint16_t YScale;
	uint16_t XScaleA;
	uint16_t XScaleB;
}particalInfoBlock;

typedef struct particalPix {
	int left_pix;
	int right_pix;
}particalPix;

typedef struct partical {
	float t;
	float d;									
	float v;									
	float obl_a;							
	float obl_b;								
	float obl;									
	int A_X_scale;
	int B_X_scale;
	int Y_scale;
	vector<particalPix> Aline;
	vector<particalPix> Bline;
}partical;

typedef struct Product {
	int t;
	int dsd[150];
	double ni[150];
	float dMax;
	double rainRate;
	double ref;
	double massWeightedMeanDiameter;
	double medianVolumeDiameter;
}product;

class C2DVD_HYD
{
public:
	C2DVD_HYD();
	~C2DVD_HYD();
private:
	int m_error_mk;
public:
	bool Decode(string filePath, bool qualityControl);
	string GetErrorMsg();
};

