
var express = require('express');
var app = express();
app.set('view engine', 'pug')
var msg = "";
var SerialPort = require('serialport');
var port = new SerialPort.SerialPort('/dev/ttyACM0',
{
baudRate:9600,
dataBits:8,
parity:'none',
stopBits:1,
flowControl:false,
parser:SerialPort.parsers.readline("\r\n")
});
 
port.on('open', function() {
  port.write('main screen turn on', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('message written');
  });
});

port.on("data", function(message) { msg = message;console.log(message)});


app.get('/', function (req, res) {

	//var myPage = "<html><head><title>Coucou :)</title></head><body><div id='truc'></div><script>setInterval(function() {}, 3000);</script></body></html>";
  //res.send(msg);
	res.render('index', { title: 'Hey', message: 'Hello there!', detail: msg })
});


app.get('/state', function (req, res) {

	res.send(msg)
});

app.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});


