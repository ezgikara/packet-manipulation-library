#include "ipv6test.h"

Ipv6Test::Ipv6Test(QObject *parent) :
    QObject(parent)
{
}

void Ipv6Test::testPacketCreation()
{
  //40 bytes IPv6 header taken from a wireshark dump
  uint8_t bits[] = { 0x60, 0x00, 0x00, 0x00, 0x00, 0x18, 0x06, 0x40, 0x20, 0x01,
          0x04, 0x80, 0x15, 0x40, 0x01, 0x68, 0x02, 0x24, 0xe8, 0xff, 0xfe, 0xa4,
          0x54, 0xea, 0x20, 0x01, 0x48, 0x60, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x68 };

  //construct IPv6 header from bytes above
  IPv6 ipv6( bits, 40 );

  QEXPECT_FAIL( "", "IPv6 Needs some work", Continue );
  QCOMPARE( ipv6.version(), 6U );
}