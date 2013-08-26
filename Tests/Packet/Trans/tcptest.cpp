#include "tcptest.h"

TcpTest::TcpTest(QObject *parent) :
  QObject(parent)
{
}

void TcpTest::testConstruction()
{
  //20 bytes tcp header taken from wireshark dump
  uint8_t bits[] = { 0x00, 0x50, 0x60, 0x5d, 0x48, 0x5b, 0x27, 0xa6, 0xd3,
                     0xa5, 0xeb, 0xac, 0x50, 0x12, 0x16, 0x58, 0xd6, 0x59, 0x00, 0x00 };

  //construct tcp header from bytes above
  TCP tcp_1( bits, 20 );

  //copy tcp header
  TCP tcp_2( tcp_1 );

  //check is tcp
  QVERIFY( tcp_1.isTCP() );
  QVERIFY( tcp_2.isTCP() );

  //check source port
  QVERIFY( tcp_1.sourcePort() == 0x0050 );
  //check set source port
  tcp_1.setSourcePort( 0x0099 );
  QVERIFY( tcp_1.sourcePort() == 0x0099 );

  //check dest port
  QVERIFY( tcp_1.destinationPort() == 0x605d );
  //check set dest port
  tcp_1.setDestinationPort( 0x0666 );
  QVERIFY( tcp_1.destinationPort() == 0x0666 );

  //check seq #
  QVERIFY( tcp_1.sequenceNumber() == 0x485b27a6 );
  //check seq #
  tcp_1.setSequenceNumber( 0x40506070 );
  QVERIFY( tcp_1.sequenceNumber() == 0x40506070 );

  //check ack #
  QVERIFY( tcp_1.acknowledgementNumber() == 0xd3a5ebac );
  //check set ack #
  tcp_1.setAcknowledgementNumber( 0x11223344 );
  QVERIFY( tcp_1.acknowledgementNumber() == 0x11223344 );

  //check data offset
  QVERIFY( tcp_1.dataOffset() == 20 );
  //check set data offset
  tcp_1.setDataOffset( 28 );
  QVERIFY( tcp_1.dataOffset() == 28 );

  //check return reserved data after data offset
  QVERIFY( tcp_1.x2() == 0x00 );
  //check set reserved data
  tcp_1.setX2( 0x01 );
  QVERIFY( tcp_1.x2() == 0x01 );

  //check CWR flag
  QVERIFY( tcp_1.CWR_Flag() == false );
  //check set CWR flag
  tcp_1.setCWR_Flag( true );
  QVERIFY( tcp_1.CWR_Flag() );
  tcp_1.setCWR_Flag( false );
  QVERIFY( tcp_1.CWR_Flag() == false );
  //set flag to true
  tcp_1.setCWR_Flag();
  QVERIFY( tcp_1.CWR_Flag() );

  //check ECE flag
  QVERIFY( tcp_1.ECE_Flag() == false );
  //check set ECE flag
  tcp_1.setECE_Flag( true );
  QVERIFY( tcp_1.ECE_Flag() );
  tcp_1.setECE_Flag( false );
  QVERIFY( tcp_1.ECE_Flag() == false );
  //set flag to true
  tcp_1.setECE_Flag();
  QVERIFY( tcp_1.ECE_Flag() );

  //check URG flag
  QVERIFY( tcp_1.URG_Flag() == false );
  //check set URG flag
  tcp_1.setURG_Flag( true );
  QVERIFY( tcp_1.URG_Flag() );
  tcp_1.setURG_Flag( false );
  QVERIFY( tcp_1.URG_Flag() == false );
  //set flag to true
  tcp_1.setURG_Flag();
  QVERIFY( tcp_1.URG_Flag() );

  //check ACK flag
  QVERIFY( tcp_1.ACK_Flag() );
  //check set ACK flag
  tcp_1.setACK_Flag( false );
  QVERIFY( tcp_1.ACK_Flag() == false );
  tcp_1.setACK_Flag( true );
  QVERIFY( tcp_1.ACK_Flag() );
  tcp_1.setACK_Flag( false ); //set back to false
  //set flag to true
  tcp_1.setACK_Flag();
  QVERIFY( tcp_1.ACK_Flag() );

  //check PSH flag
  QVERIFY( tcp_1.PSH_Flag() == false );
  //check set PSH flag
  tcp_1.setPSH_Flag( true );
  QVERIFY( tcp_1.PSH_Flag() );
  tcp_1.setPSH_Flag( false );
  QVERIFY( tcp_1.PSH_Flag() == false );
  //set flag to true
  tcp_1.setPSH_Flag();
  QVERIFY( tcp_1.PSH_Flag() );

  //check RST flag
  QVERIFY( tcp_1.RST_Flag() == false );
  //check set RST flag
  tcp_1.setRST_Flag( true );
  QVERIFY( tcp_1.RST_Flag() );
  tcp_1.setRST_Flag( false );
  QVERIFY( tcp_1.RST_Flag() == false );
  //set flag to true
  tcp_1.setRST_Flag();
  QVERIFY( tcp_1.RST_Flag() );

  //check SYN flag
  QVERIFY( tcp_1.SYN_Flag() );
  //check set SYN flag
  tcp_1.setSYN_Flag( false );
  QVERIFY( tcp_1.SYN_Flag() == false );
  tcp_1.setSYN_Flag( true );
  QVERIFY( tcp_1.SYN_Flag() );
  tcp_1.setSYN_Flag( false ); //set back to false
  //set flag to true
  tcp_1.setSYN_Flag();
  QVERIFY( tcp_1.SYN_Flag() );

  //check FIN flag
  QVERIFY( tcp_1.FIN_Flag() == false );
  //check set FIN flag
  tcp_1.setFIN_Flag( true );
  QVERIFY( tcp_1.FIN_Flag() );
  tcp_1.setFIN_Flag( false );
  QVERIFY( tcp_1.FIN_Flag() == false );
  //set flag to true
  tcp_1.setFIN_Flag();
  QVERIFY( tcp_1.FIN_Flag() );

  //check then set window size
  QVERIFY( tcp_1.windowSize() == 0x1658 );
  tcp_1.setWindowSize( 0x1111 );
  QVERIFY( tcp_1.windowSize() == 0x1111 );

  //check then set checksum
  QVERIFY( tcp_1.checksum() == 0xd659 );
  tcp_1.setChecksum( 0xd666 );
  QVERIFY( tcp_1.checksum() == 0xd666 );

  //check then set urgent pointer
  QVERIFY( tcp_1.urgentPointer() == 0x0000 );
  tcp_1.setUrgentPointer( 0x0001 );
  QVERIFY( tcp_1.urgentPointer() == 0x0001 );

  //check the size
  QCOMPARE( tcp_1.size(), tcp_2.size() );
  QVERIFY( tcp_1.size() == 20 );
}


void TcpTest::testConstruction2()
{
  //testing what happens when we give too much data...

  uint8_t bits[] = { 0xc6, 0xe0, 0x00, 0x50, 0x33, 0xe5, 0xd2, 0xd8, 0x24, 0x26, 0xeb, 0xe1, 0x50, 0x18, 0x00, 0x73,
  0x38, 0x1f, 0x00, 0x00, 0x47, 0x45, 0x54, 0x20, 0x2f, 0x62, 0x6c, 0x61, 0x76, 0x61, 0x74, 0x61, 0x72, 0x2f, 0x64,
  0x34, 0x62, 0x39, 0x31, 0x64, 0x31, 0x33, 0x38, 0x62, 0x32, 0x66, 0x61, 0x36, 0x39, 0x36, 0x63, 0x38, 0x62, 0x39,
  0x34, 0x61, 0x37, 0x62, 0x37, 0x30, 0x35, 0x61, 0x61, 0x33, 0x32, 0x61, 0x3f, 0x73, 0x3d, 0x31, 0x36, 0x20, 0x48,
  0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x31, 0x0d, 0x0a, 0x48, 0x6f, 0x73, 0x74, 0x3a, 0x20, 0x31, 0x2e, 0x67, 0x72,
  0x61, 0x76, 0x61, 0x74, 0x61, 0x72, 0x2e, 0x63, 0x6f, 0x6d, 0x0d, 0x0a, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74,
  0x69, 0x6f, 0x6e, 0x3a, 0x20, 0x6b, 0x65, 0x65, 0x70, 0x2d, 0x61, 0x6c, 0x69, 0x76, 0x65, 0x0d, 0x0a, 0x41, 0x63,
  0x63, 0x65, 0x70, 0x74, 0x3a, 0x20, 0x2a, 0x2f, 0x2a, 0x0d, 0x0a, 0x44, 0x4e, 0x54, 0x3a, 0x20, 0x31, 0x0d, 0x0a,
  0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65, 0x6e, 0x74, 0x3a, 0x20, 0x4d, 0x6f, 0x7a, 0x69, 0x6c, 0x6c, 0x61,
  0x2f, 0x35, 0x2e, 0x30, 0x20, 0x28, 0x58, 0x31, 0x31, 0x3b, 0x20, 0x4c, 0x69, 0x6e, 0x75, 0x78, 0x20, 0x78, 0x38,
  0x36, 0x5f, 0x36, 0x34, 0x29, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x57, 0x65, 0x62, 0x4b, 0x69, 0x74, 0x2f, 0x35,
  0x33, 0x37, 0x2e, 0x33, 0x31, 0x20, 0x28, 0x4b, 0x48, 0x54, 0x4d, 0x4c, 0x2c, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20,
  0x47, 0x65, 0x63, 0x6b, 0x6f, 0x29, 0x20, 0x43, 0x68, 0x72, 0x6f, 0x6d, 0x65, 0x2f, 0x32, 0x36, 0x2e, 0x30, 0x2e,
  0x31, 0x34, 0x31, 0x30, 0x2e, 0x36, 0x33, 0x20, 0x53, 0x61, 0x66, 0x61, 0x72, 0x69, 0x2f, 0x35, 0x33, 0x37, 0x2e,
  0x33, 0x31, 0x0d, 0x0a, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d, 0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67,
  0x3a, 0x20, 0x67, 0x7a, 0x69, 0x70, 0x2c, 0x64, 0x65, 0x66, 0x6c, 0x61, 0x74, 0x65, 0x2c, 0x73, 0x64, 0x63, 0x68,
  0x0d, 0x0a, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d, 0x4c, 0x61, 0x6e, 0x67, 0x75, 0x61, 0x67, 0x65, 0x3a, 0x20,
  0x65, 0x6e, 0x2d, 0x55, 0x53, 0x2c, 0x65, 0x6e, 0x3b, 0x71, 0x3d, 0x30, 0x2e, 0x38, 0x0d, 0x0a, 0x41, 0x63, 0x63,
  0x65, 0x70, 0x74, 0x2d, 0x43, 0x68, 0x61, 0x72, 0x73, 0x65, 0x74, 0x3a, 0x20, 0x49, 0x53, 0x4f, 0x2d, 0x38, 0x38,
  0x35, 0x39, 0x2d, 0x31, 0x2c, 0x75, 0x74, 0x66, 0x2d, 0x38, 0x3b, 0x71, 0x3d, 0x30, 0x2e, 0x37, 0x2c, 0x2a, 0x3b,
  0x71, 0x3d, 0x30, 0x2e, 0x33, 0x0d, 0x0a, 0x0d, 0x0a };

  TCP tcp( bits, 366 );
  QCOMPARE( tcp.size(), 20 );

  //now with options.

  uint8_t bits2[] = {  0x00, 0x16, 0xa8, 0x6d, 0x2a, 0x66, 0x15, 0x8f, 0xae, 0x82, 0x16, 0x9d, 0x80, 0x18, 0x00, 0x72,
  0x15, 0xc4, 0x00, 0x00, 0x01, 0x01, 0x08, 0x0a, 0x00, 0x4c, 0xc6, 0xb4, 0x00, 0x29, 0xcc, 0x0a, 0x53, 0x53, 0x48,
  0x2d, 0x32, 0x2e, 0x30, 0x2d, 0x4f, 0x70, 0x65, 0x6e, 0x53, 0x53, 0x48, 0x5f, 0x36, 0x2e, 0x32, 0x0d, 0x0a }; 

  TCP tcp2( bits2, 53 );
  QCOMPARE( tcp2.size(), 32 );

  //bits that fail in packetbuilder
  uint8_t bits3[] = { 0xb1, 0xdd, 0x23, 0x28, 0xbc, 0x43, 0x1d, 0x35, 0x7d, 0x1f, 0x8b, 0x9d,
                      0xb0, 0x18, 0x00, 0x73, 0xf2, 0x5e, 0x00, 0x00, 0x01, 0x01, 0x08, 0x0a, 0x00, 0x0e, 0x77, 0x19,
                      0x2b, 0x74, 0x0e, 0x00, 0x01, 0x01, 0x05, 0x0a, 0x7d, 0x1f, 0x8b, 0x9e, 0x7d, 0x1f, 0x8b, 0xb9,
                      0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00 };

  TCP tcp3( bits3, 61 );
  QCOMPARE( tcp3.makePacket().size(), 44 );
}

void TcpTest::testOptions()
{
  //28 bytes tcp header taken from wireshark dump
  //(min header size = 20bytes; max size = 60bytes)
          uint8_t bits[] = { 0x05, 0xde, 0x00, 0x50, 0xa9, 0xde, 0x0d, 0xd5, 0x00,
                  0x00, 0x00, 0x00, 0x60, 0x02, 0x40, 0x00, 0x37, 0xa4, 0x00, 0x00, 0x02,
                  0x04, 0x05, 0xa0 };

  //construct tcp header from bytes above
  TCP tcp_3( bits, 24 );

  //copy tcp header
  TCP tcp_3A( tcp_3 );

  //check size
  QCOMPARE( tcp_3.size(), 24 );
  //check size of copy
  QCOMPARE( tcp_3A.size(), 24 );
  //compare sizes
  QCOMPARE( tcp_3.size(), tcp_3A.size() );

  //check erase all options
  tcp_3.clearOptions();
  tcp_3A.clearOptions();

  QCOMPARE( tcp_3.size(), tcp_3A.size() );

  //add Maximum Segment Size option
  SmartPtr< TCPOption > mssOption = new MSSOption();
  tcp_3.addOption( mssOption );
  QCOMPARE( tcp_3.size(), 24 );

  //add NOP Option
  tcp_3.clearOptions();
  SmartPtr< TCPOption > noopOption = new NOOPOption();
  tcp_3.addOption( noopOption );
  QCOMPARE( tcp_3.size(), 21 );

  //add Sack Permitted option
  tcp_3.clearOptions();
  SmartPtr< TCPOption > sackPermittedOption = new SACKPremittedOption();
  tcp_3.addOption( sackPermittedOption );
  QCOMPARE( tcp_3.size(), 22 );

  //add Time Stamp option
  tcp_3.clearOptions();
  SmartPtr< TCPOption > timeStampOption = new TimeStampOption();
  tcp_3.addOption( timeStampOption );
  QCOMPARE( tcp_3.size(),  30 );

  //add WSOPT - Window Scale option
  tcp_3.clearOptions();
  SmartPtr< TCPOption > wsOption = new WSOption();
  tcp_3.addOption( wsOption );
  QCOMPARE( tcp_3.size(), 23 );

  //add Sack option
  //method 1
  tcp_3.clearOptions();
  SmartPtr< TCPOption > sackOption = new SACKOption();
  tcp_3.addOption( sackOption );
  QCOMPARE( tcp_3.size(), 22 );

  //add eolOption
  tcp_3.clearOptions();
  SmartPtr< TCPOption > eolOption = new EOLOption();
  tcp_3.addOption( eolOption );
  QVERIFY( tcp_3.size() != tcp_3A.size() );

  uint8_t timeStampBits[] = { 0x08, 0x0A, 0x00, 0x07, 0x6A, 0xAD, 0xD9, 0xEA, 0x13, 0x9B }; //TSval 486061 TSecr 3655996315
  int timeStampSize = 10;

  TimeStampOption timestamp(timeStampBits, timeStampSize);
  QCOMPARE( timestamp.tsecr(), 0xd9ea139bU );
  QCOMPARE( timestamp.tsval(), 0x00076AADU );
  timestamp.setTSecr( 0xDEADBEEF );
  timestamp.setTSVAL( 0xCAFE1337 );
  QCOMPARE( timestamp.tsecr(), 0xDEADBEEFU );
  QCOMPARE( timestamp.tsval(), 0xCAFE1337U );
}
