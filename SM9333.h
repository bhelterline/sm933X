// SM9333.h
#ifndef SM9333_H
#define SM9333_H

#define P_MIN -125
#define P_MAX 125
#define b0 -16881
#define b1 397.2

#define SM9333_UNPROTECTED 0x6C
#define SM9333_CRC_PROTECTED 0x6D

struct pressureTemperaturePair {
        double pressure;
        double temperature;
};

class SM9333
{
public:
    // consructor
    SM9333();
	
	bool begin();

    // checks if the chip is connected
    bool isConnected();

    // Returns a pressure reading
    double readPressure();

    // Returns a temperature reading
    double readTemperature();

    struct commandSequence {
        int* sequence;
        int length;
    };

    // Returns pressure and temperature readings (they're always sent by the chip at the same time)
    pressureTemperaturePair readBoth();

private:

    // using the low byte and high byte sent by the chip, calculates the Pressure using bitwise math and
    // also the equation provided in the datasheet.
    double calculatePressure(int pressureLowBit, int pressureHighBit);

    // using the low Byte and high Byte sent by the chip, calculates the Temperature using bitwise math and
    // also the equation provided in the datasheet.
    double calculateTemperature(int temperatureLowByte, int temperatureHighByte);

    // used to write a sequence of bits to the chip
    void writer(commandSequence seq);

    // requests a read from the chip of numBits number of bits, and with or without CRC protection
    int* doRead(int numBits, bool crcProtected, int location);

};


#endif
