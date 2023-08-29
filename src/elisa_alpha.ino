#define MOTOR_SPEED 120

/* Enable pins for motors */

uint8_t ena = 6;
uint8_t enb = 7;

/* Polarity pins for motors */

uint8_t in1 = 8;
uint8_t in2 = 9;
uint8_t in3 = 10;
uint8_t in4 = 11;

/* IR pins */

uint8_t ir_left = 5;
uint8_t ir_right = 3;

/* Define array for inputs */

uint8_t input_pins[] = {ir_left, ir_right};
uint8_t output_pins[] = {ena, enb, in1, in2, in3, in4};

/**
* robot_s - struct consisting of robot parameters
* 
* @speed: speed of the robot
* @ena: enable pin a
* @enb: enable pin b
* @in_a: polarity 1 for motor a
* @in_b: polarity 2 for motor a
* @in_c: polarity 1 for motor b
* @in_d: polarity 2 for motor b
* @ir_left: Digital pin for IR left
* @ir_right: Digital pin for IR right
*/

typedef struct robot_s
{
    uint8_t speed;
    uint8_t ena;
    uint8_t enb;
    uint8_t in_a;
    uint8_t in_b;
    uint8_t in_c;
    uint8_t in_d;
    uint8_t ir_left;
    uint8_t ir_right;
}   robot_t;

uint8_t switch_on(void);
void switch_off(void);
uint8_t e_detect_black_line(uint8_t ir);

void forward(unsigned long int motor_speed_r, unsigned long int motor_speed_l);
void backward(unsigned long int motor_speed_r, unsigned long int motor_speed_l);
void left(unsigned long int motor_speed_r, unsigned long int motor_speed_l);
void right(unsigned long int motor_speed_r, unsigned long int motor_speed_l);

uint8_t _set_motor_speed(void param);

robot_t _robot_start(void);
robot_t _robot_restart(void);
robot_t follow_line(void);

/**
* setup - initialize robot variables and start motors
* @param void
* @return none
*/

void setup(void)
{
  int i = 0, j = 0;

  for (i = 0; i < 5; i++)
  {
      pinMode(output_pins[i], OUTPUT);
  }

  for (j = 0; i < 1; j++)
  {
      pinMode(input_pins[j], INPUT);
  }
  
}

/**
* loop - reocurring program
* @param none
* @return void
*/

void loop(void)
{

}

/**
* switch_on - switches the robot on
* @param: none
* @return 0 or -1
*/

uint8_t switch_on(void)
{
    if (motor_speed != NULL)
    {
      analogWrite(ena, (int) motor_speed);
      analogWrite(enb, (int) motor_speed);
      return (0);
    }
    else
    {
      return (-1);
    }
}

/**
* switch_off - switches the robot off
* @param none
* @return none
*/

void switch_off(void)
{
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
}

/**
* e_detect_black_line - returns 0 if a sensor detects a black line
*
* @param ir: ir sensor pin
* @return 0 or -1 
*/

uint8_t e_detect_black_line(uint8_t ir)
{
  int val = digitalRead(ir);

  if (val == HIGH)
  {
    return (0);
  }

  else
  {
    return (-1);
  }
}

/**
* _forward - move the robot forward
* @param motor_speed_r - speed of the right motor
* @param motor_speed_l - speed of the left motor
* @return void
*/

void forward(unsigned long int motor_speed_r, unsigned long int motor_speed_l)
{

  if (_set_motor_speed(MOTOR_SPEED))
  {
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);

      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
  }

}

/**
* backward - move the robot backward
* @param motor_speed_r - speed of the right motor
* @param motor_speed_l - speed of the left motor
* @return void
*/

void backward(unsigned long int motor_speed_r, unsigned long int motor_speed_l)
{
    if (_set_motor_speed(MOTOR_SPEED))
    {
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);

        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
    }

}

/**
* left - move the robot left
* @param motor_speed_r - speed of the right motor
* @param motor_speed_l - speed of the left motor
* @return void
*/

void left(unsigned long int motor_speed_r, unsigned long int motor_speed_l)
{
    if (_set_motor_speed(MOTOR_SPEED))
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);

        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
    }

}

/**
* right - move the robot right
* @param motor_speed_r - speed of the right motor
* @param motor_speed_l - speed of the left motor
* @return void
*/


void right(unsigned long int motor_speed_r, unsigned long int motor_speed_l)
{
    if (_set_motor_speed(MOTOR_SPEED))
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);

        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
    }

}

/**
* _set_motor_speed - move the robot left
* @param (void) param: speed to set
* @return: 0 or -1
*/

uint8_t _set_motor_speed(void param)
{
  if (param)
  {
    int speed = (uint8_t) param;
    analogWrite(ena, speed);
    analogWrite(enb, speed);
    return (0);
  }
  else
  {
    return (-1);
  }
}

/**
* _robot_start - start the robot
* @param (void)
* @return: robot_t struct
*/

robot_t _robot_start(void)
{

}

/**
* _robot_restart - restart the robot
* @param (void)
* @return: robot_t struct
*/

robot_t _robot_restart(void)
{

}

/**
* follow_line - follow line
* @param (void)
* @return: robot_t
*/

robot_t follow_line(void)
{

}
