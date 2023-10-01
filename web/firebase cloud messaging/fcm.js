import { useEffect } from 'react';
import firebase from 'firebase/app';
import 'firebase/messaging';

// Initialize Firebase
const firebaseConfig = {
  // Your Firebase config here
};

firebase.initializeApp(firebaseConfig);

const YourComponent = () => {
  useEffect(() => {
    const requestNotificationPermission = async () => {
      try {
        const messaging = firebase.messaging();
        await messaging.requestPermission();
        console.log('Notification permission granted.');

        const token = await messaging.getToken();
        console.log('Registration token:', token);

        // Send the registration token to your server for further processing/storage if needed
      } catch (error) {
        console.log('Error retrieving registration token:', error);
      }
    };

    const sendNotification = async () => {
      try {
        const messaging = firebase.messaging();
        const registrationToken = 'DEVICE_REGISTRATION_TOKEN'; // Replace with the actual device registration token

        await messaging.send({
          token: registrationToken,
          notification: {
            title: 'Notification Title',
            body: 'Notification Description',
            image: 'URL_TO_IMAGE', // Replace with the URL of the image you want to send
          },
        });

        console.log('Notification sent successfully.');
      } catch (error) {
        console.log('Unable to send notification.', error);
      }
    };

    requestNotificationPermission().then(() => {
      sendNotification();
    });
  }, []);

  // Rest of your component code
};
