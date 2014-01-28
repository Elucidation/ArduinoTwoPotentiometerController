/*
Reads in potentiometer analog values (range 0 to 1023) from pins A & B.
Converts values to 0-100 range.
It then publishes them as a Point where the x,y values are the pot values
The z value stays at zero
*/
#include <ros.h>
#include <geometry_msgs/Point.h>

#define pinA A1
#define pinB A0

#define LOOP_DELAY_MS 2

ros::NodeHandle  nh;
geometry_msgs::Point pt_msg;

ros::Publisher pot_topic("pot_vals", &pt_msg);


void setup()
{
  nh.initNode();
  nh.advertise(pot_topic);
}

void loop() {
  // Generate Message
  pt_msg.x = float(analogRead(pinA)) / 1023.0 * 100.0;
  pt_msg.y = float(analogRead(pinB)) / 1023.0 * 100.0;
  pt_msg.z = 0.0;

  // Publish message and spin once
  pot_topic.publish( &pt_msg );
  nh.spinOnce();

  // Time to wait for the analog-to-digital converter to settle
  // after the last reading.
  delay(LOOP_DELAY_MS);
}