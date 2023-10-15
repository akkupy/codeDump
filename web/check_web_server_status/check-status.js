const http = require('http');

const options = {
  host: 'yourapi.in',
  port: 80,
  path: '/'
};




try{
  setInterval(() => {
    http.get(options, (res) => {
      console.log(`Pinged server with status code: ${res.statusCode}`);
    });
  }, 30000);
}
catch(err) {
console.log(err)
}
