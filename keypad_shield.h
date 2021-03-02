#define BOT_RIGHT  0
#define BOT_UP     1
#define BOT_DOWN   2
#define BOT_LEFT   3
#define BOT_SELECT 4
#define BOT_NONE   5

// read the buttons
int read_LCD_buttons()
	{
	unsigned int adc_key_in;
	adc_key_in = analogRead(0);      // read the value from the sensor
	//adc_key_in = LeerADC(0);
  //return adc_key_in;
/*
	// my buttons when read are centered at these valies: 0, 144, 329, 504, 741
	// we add approx 50 to those values and check to see if we are close
	if (adc_key_in > 1000) return (BOT_NONE); // We make this the 1st option for speed reasons since it will be the most likely result
	// For V1.1 us this threshold
	if (adc_key_in < 50)   return (BOT_RIGHT);
	if (adc_key_in < 250)  return (BOT_UP);
	if (adc_key_in < 400)  return (BOT_DOWN);
	if (adc_key_in < 650)  return (BOT_LEFT);
	if (adc_key_in < 850)  return (BOT_SELECT);
*/
	// For V1.0 comment the other threshold and use the one below:
	
	  if (adc_key_in < 50)   return (BOT_RIGHT);
	  if (adc_key_in < 195)  return (BOT_UP);
	  if (adc_key_in < 380)  return (BOT_DOWN);
	  if (adc_key_in < 555)  return (BOT_LEFT);
	  if (adc_key_in < 790)  return (BOT_SELECT);
	
	return (BOT_NONE);  // when all others fail, return this...
	}
