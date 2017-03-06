var configData;
var configData;
var configData;
var configData;

Pebble.addEventListener('showConfiguration', function() {
  var url = 'http://example.com/config.html';

  Pebble.openURL(url);
});

// Send to the watchapp via AppMessage
var dict = {
  'BackgroundColor': configData.background_color,
  'ForegroundColor': configData.foreground_color,
  'SecondTick': configData.second_ticks,
  'Animations': configData.animations
};

// Send to the watchapp
Pebble.sendAppMessage(dict, function() {
  console.log('Config data sent successfully!');
}, function(e) {
  console.log('Error sending config data!');
});
