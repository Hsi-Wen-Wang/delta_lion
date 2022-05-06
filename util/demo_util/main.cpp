#include "Delta.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main() {
    Delta arm;
    arm.connect("192.168.2.232", 502);
    arm.setServoState(1);
    // this_thread::sleep_for(std::chrono::milliseconds(1000));
    //    arm.setServoState(0);

    vector<uint16_t> temperature = arm.getAxisTemperature();
    cout << "axisTemperature: ";
    for (uint16_t t : temperature) {
        cout << t << ", ";
    }
    cout << endl;

    vector<double> jointDegree = arm.getCurrentJoint();
    cout << "jointDegree: ";
    for (double t : jointDegree) {
        cout << t << ", ";
    }
    cout << endl;

    char inputKey=0;

    vector<double> position = arm.getCurrentPosition();
    cout << "position: ";
    for (double t : position) {
        cout << t << ", ";
    }
    cout << endl;

    arm.setOperationMode(1);

    int speed=10,accel=20,unit=5;

    arm.setSpeed(speed);
    cout << "speed: " << arm.getSpeed() << "%" << endl;
    arm.setAcceleration(accel);
    cout << "accel: " << arm.getAcceleration() << "%" << endl;

    arm.setDeceleration(50);
    cout << "decel: " << arm.getDeceleration() << "%" << endl;

    // arm.goHome();
    // arm.waitForIdle();

    double home[6] = {0, 0, 0, 0, 90, 0};
    double grip[6] = {0, 0, 0, 0, -35, 0};
    double move1[6]= {0,85,-85,0,-35,0};
    double move2_1[6]= {0,0,0,15,0,0};
    double move2_2[6]= {0,0,0,-30,0,0};
    double move3_1[6]= {30,0,0,0,0,0};
    double move3_2[6]= {-30,0,0,0,0,0};
    //double move5_1[6]= {0,0,25,0,-35,0};
    double move5_2[6]= {0,9,-4,-20,0,0};
    double move5_3[6]= {0,9,-4,20,0,0};
//    double move5_4[6]= {0,9,-4,10,0,0};
    double move6[6]= {0,-90,65,-10,-35,0};
    double move7[6]= {-45,70,-35,-25,-35,0};
    double move8[6]= {20,15,-30,0,-35,0};
    double move9[6]= {-20,15,-30,0,-35,0};


 //   arm.moveLinAbsJoint(home);
 //   arm.waitForIdle();



    double joint1[6] = {0, 0, 0, 0, 0, 0};

    while(inputKey !=27){
	    if(inputKey == 'q'){
		joint1[0]=-unit;
		arm.moveLinRelJoint(joint1);
		arm.waitForIdle();
		joint1[0]=0;
	    }
        else if(inputKey == 'w'){
            joint1[0]=unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[0]=0;
        }
        else if(inputKey == 'a'){
            joint1[1]=-unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[1]=0;
        }
        else if(inputKey == 's'){
            joint1[1]=unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[1]=0;
        }
        else if(inputKey == 'z'){
            joint1[2]=-unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[2]=0;
        }
        else if(inputKey == 'x'){
            joint1[2]=unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[2]=0;
        }
        else if(inputKey == 'e'){
            joint1[3]=-unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[3]=0;
        }
        else if(inputKey == 'r'){
            joint1[3]=unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[3]=0;
        }
        else if(inputKey == 'd'){
            joint1[4]=-unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[4]=0;
        }
        else if(inputKey == 'f'){
            joint1[4]=unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[4]=0;
        }
        else if(inputKey == 'c'){
            joint1[5]=-unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[5]=0;
        }
        else if(inputKey == 'v'){
            joint1[5]=unit;
            arm.moveLinRelJoint(joint1);
            arm.waitForIdle();
            joint1[5]=0;
        }
        else if( inputKey == 'h' ){
            arm.movePtpAbsJoint(home);
            arm.waitForIdle();
        }
        else if(inputKey=='u'){
            cout<<"unit is "<<unit<<" now, input new value"<<endl;
            scanf("%d", &unit);
        }
        else if(inputKey=='j'){
            jointDegree = arm.getCurrentJoint();
            cout << "jointDegree: ";
            for (double t : jointDegree) {
                cout << t << ", ";
            }
        }
        else if(inputKey=='p'){
            cout<<"speed is "<<speed<<" now, input new value"<<endl;
            scanf("%d", &speed);
            arm.setSpeed(speed);
            cout << "speed: " << arm.getSpeed() << "%" << endl;
        }
        else if(inputKey=='o'){
            cout<<"accel is "<<accel<<" now, input new value"<<endl;
            scanf("%d", &accel);
            arm.setAcceleration(accel);
            cout << "accel: " << arm.getAcceleration() << "%" << endl;
        }
	else if(inputKey=='g'){
		arm.movePtpAbsJoint(grip);
		arm.waitForIdle();
	}
	else if(inputKey=='1'){
                arm.movePtpAbsJoint(move1);
                arm.waitForIdle();
        }
	else if(inputKey=='2'){
                arm.movePtpRelJoint(move2_1);
                arm.waitForIdle();

	        arm.movePtpRelJoint(move2_2);
                arm.waitForIdle();

		 arm.movePtpRelJoint(move2_1);


                arm.waitForIdle();
        }
        else if(inputKey=='3'){
                arm.movePtpRelJoint(move3_1);
                arm.waitForIdle();
        }
        else if(inputKey=='4'){
                arm.movePtpRelJoint(move3_2);
                arm.waitForIdle();
        }
	      else if(inputKey=='5'){
                jointDegree = arm.getCurrentJoint();
		arm.setSpeed(10);
                while(jointDegree[1]<=-0.2 || jointDegree[2]>=25.2){
                    arm.movePtpRelJoint(move5_3);
                    jointDegree = arm.getCurrentJoint();
                    while(jointDegree[3]<=9.8){
                        jointDegree = arm.getCurrentJoint();
		    }
                    arm.movePtpRelJoint(move5_2);

                    while(jointDegree[3]>=-9.8){
                        jointDegree = arm.getCurrentJoint();
                    }

                }
                arm.waitForIdle();
		arm.setSpeed(speed);
        }
	        else if(inputKey=='6'){
                arm.movePtpAbsJoint(move6);
                arm.waitForIdle();
        }
		else if(inputKey=='7'){
		arm.movePtpAbsJoint(move7);
                arm.waitForIdle();
		}
                else if(inputKey=='8'){
                arm.movePtpAbsJoint(move8);
                arm.waitForIdle();
                }
                else if(inputKey=='9'){
                arm.movePtpAbsJoint(move9);
                arm.waitForIdle();
                }

        scanf("%c",&inputKey);

    }
 //   arm.movePtpAbsCoord(shift);
    arm.waitForIdle();

    // for (int m = 0; m < 10; m++) {
    //    for (int k = 0; k < 2; k++) {
    //        coords[0] = 350 - 100 + (100 * k);
    //        for (int i = 0; i < 2; i++) {
    //            coords[2] = 674 - 300 + (300 * i);
    //            for (int j = 0; j < 13; j++) {
    //                coords[1] = 0 - (6 * 50) + (j * 50);
    //                arm.movePtpAbsCoord(coords);
    //                arm.waitForIdle();
    //            }
    //        }
    //    }
    //}

    // this_thread::sleep_for(std::chrono::milliseconds(5000));
 //   arm.movePtpAbsJoint(home);
 //   arm.waitForIdle();

    // this_thread::sleep_for(std::chrono::milliseconds(5000));
    // arm.goHome();

    // arm.waitForIdle();
    // this_thread::sleep_for(std::chrono::milliseconds(5000));
    arm.setServoState(0);
    return 0;
}

