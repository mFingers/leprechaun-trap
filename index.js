var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
  // var led = new five.Led(11);
  // led.brightness(255);
  // led.fade(10, 3000, () => led.blink(500));

  var servo = new five.Servo({pin: 10, range: []});
  servo.sweep();
});
