


void SetupVibration(){
//  set up the pins for the motors
      pinMode(thumb, OUTPUT);
      pinMode(index, OUTPUT);  
      pinMode(middle_finger, OUTPUT);
}

void VibrationLoop(bool* bool_array, int length){
  bool finger_thumb =  bool_array[0];
  bool finger_index = bool_array[1];
  bool finger_middle = bool_array[2];
  
  digitalWrite(thumb, BooleanMapper(finger_thumb));
  digitalWrite(index, BooleanMapper(finger_index));
  digitalWrite(middle_finger, BooleanMapper(finger_middle));
}

int BooleanMapper(bool value){
  return value?HIGH:LOW;
  }
