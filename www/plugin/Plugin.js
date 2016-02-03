
  var Plugin = function() {
    this.callbackId = null;
  }

  Plugin.prototype.setCallbackId = function(callbackId) {
    this.callbackId = callbackId;
  }

  Plugin.prototype.isAvailableForDevice = function() {
    return true;
  }

  module.exports = Plugin;
