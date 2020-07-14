#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

//Key codes here
//https://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct
void Type(){

	//Convert a string integer into a series of these key presses

	keybd_event(VkKeyScan('1'), 0x82, 0, 0);
	keybd_event(VkKeyScan('1'), 0x82, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('2'), 0x83, 0, 0);
	keybd_event(VkKeyScan('2'), 0x83, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('3'), 0x84, 0, 0);
	keybd_event(VkKeyScan('3'), 0x84, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('4'), 0x85, 0, 0);
	keybd_event(VkKeyScan('4'), 0x85, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('5'), 0x86, 0, 0);
	keybd_event(VkKeyScan('5'), 0x86, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('6'), 0x87, 0, 0);
	keybd_event(VkKeyScan('6'), 0x87, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('7'), 0x88, 0, 0);
	keybd_event(VkKeyScan('7'), 0x88, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('8'), 0x89, 0, 0);
	keybd_event(VkKeyScan('8'), 0x89, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('9'), 0x8A, 0, 0);
	keybd_event(VkKeyScan('9'), 0x8A, KEYEVENTF_KEYUP, 0);

	keybd_event(VkKeyScan('0'), 0x8B, 0, 0);
	keybd_event(VkKeyScan('0'), 0x8B, KEYEVENTF_KEYUP, 0);

	//TAB
	keybd_event(VK_TAB, 0x09, 0, 0);
	keybd_event(VK_TAB, 0x09, KEYEVENTF_KEYUP, 0);

}
