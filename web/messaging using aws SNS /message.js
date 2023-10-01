const AWS = require('aws-sdk');


AWS.config.update({
  accessKeyId: 'YOUR_ACCESS_KEY_ID',
  secretAccessKey: 'YOUR_SECRET_ACCESS_KEY',
  region: 'us-east-1', // Change to your desired AWS region
});

const sns = new AWS.SNS();


const params = {
  Message: 'Hello from AWS SNS!', 
  PhoneNumber: '+1234567890', 
};


sns.publish(params, (err, data) => {
  if (err) {
    console.error('Error sending SMS:', err);
  } else {
    console.log('SMS sent successfully:', data.MessageId);
  }
});
