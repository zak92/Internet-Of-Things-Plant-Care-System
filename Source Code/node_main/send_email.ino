/* 
send email to user's email address 
*/

void send_email() {
  EMailSender::EMailMessage message;
  String water_levels = reservoir_level_status;
  
  message.subject = "Reservoir water levels";
  String text4message = water_levels;
  Serial.println(text4message);
  message.message = (text4message);
  
  // YOUR_GMAIL_ADDRESS below
  EMailSender::Response resp = emailSend.send(email_address, message);
  // for testing and debugging
  Serial.println("Sending status: ");
  Serial.println(resp.status);
  
}
