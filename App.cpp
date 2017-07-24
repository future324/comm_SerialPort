#include"SerialPort.hpp"
#include<iostream>
using namespace std;

void handler(unsigned char ch,void *usrdata){
	cout << ch;
}

int main()
{
	SerialPort usart(3);
	if (!usart.isOpened())return -1;
	usart.setReceiveCallback(handler);
	usart.StartListen();
	unsigned char ch;
	while (1) {
		ch = getchar();
		usart.WriteData(&ch, 1);
	}
}