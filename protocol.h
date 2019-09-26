#ifndef PROTOCOL_H
#define PROTOCOL_H


#define SYNC_BYTE       0x00

typedef struct
{
    uint8_t cmd;
    uint8_t length;
    char data[256];
} serialPackage;

enum serialCommands
{
    CMD_REQUEST = 1,
    CMD_ACK,
    CMD_GAMEDATA,
};



#endif // PROTOCOL_H
