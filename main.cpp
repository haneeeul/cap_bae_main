#include<iostream>
#include<Python.h>

using namespace std;

int main(int argc, char *argv[]){

    bool state = false;  //
    Py_Initialize();
    PyRun_SimpleString("import sys, sys.path.append('.')"); //현재 디렉토리를 path에 추가
    PyRun_SimpleString("import AlphaBot2;");  //forward(), stop() 등 바퀴 조작 함수 포함
    PyRun_SimpleString("import RPi.GPIO;");
    PyRun_SimpleString("import time;");  //파이썬 임포트 커멘드

    PyRun_SimpleString("RPi.GPIO.setmode(RPi.GPIO.BCM)");
    PyRun_SimpleString("RPi.GPIO.setwarnings(False)");
    PyRun_SimpleString("RPi.GPIO.setup(7, RPi.GPIO.IN, RPi.GPIO.PUD_UP)");  //모터 초기화

    PyRun_SimpleString("Ab = AlphaBot2.AlphaBot2()");
    PyRun_SimpleString("print('Test Example')");
    PyRun_SimpleString("time.sleep(2)");

    while(1){  //정지
      PyRunSimpleString("Ab.stop()");
      PyRunSimpleString("time.sleep(0.1)");
      if(state == true) break;
    }
    while(state){  //state 값이 true가 되면 출발
      PyRun_SimpleString("Ab.forward()");
      PyRunSimpleString("time.sleep(0.1)");
      if(state == false) break;
    }
    Py_Finalize();

    return 0;
 }
  
