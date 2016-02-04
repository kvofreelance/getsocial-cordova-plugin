
  var Plugin = require('./Plugin')

  var NATIVE_BRIDGE_NAME = "GetSocialPluginEvents";

  var InvitePlugin = function() {
  }

  InvitePlugin.prototype.isAvailableCallbackID = function() {
    console.log(this.callbackId);
    if(this.callbackId == null)
      return false

    return true
  }

  InvitePlugin.prototype.completeCallback = function(s, list) {
    if(this.isAvailableCallbackID())
      cordova.exec(null, null, NATIVE_BRIDGE_NAME, "completeCallback", [this.callbackId, s, list]);
  }
  InvitePlugin.prototype.cancelCallback = function() {
    if(this.isAvailableCallbackID())
      cordova.exec(null, null, NATIVE_BRIDGE_NAME, "cancelCallback", [this.callbackId]);
  }
  InvitePlugin.prototype.errorCallback = function() {
    if(this.isAvailableCallbackID())
      cordova.exec(null, null, NATIVE_BRIDGE_NAME, "errorCallback", [this.callbackId]);
  }
  InvitePlugin.prototype.clickedCallback = function() {
    if(this.isAvailableCallbackID())
      cordova.exec(null, null, NATIVE_BRIDGE_NAME, "clickedCallback", [this.callbackId]);
  }


  InvitePlugin.prototype.inviteFriends = function(subject, text, referralDataUrl, image, onSuccess, onCancel, onFailure) {}

  InvitePlugin.prototype.__proto__ = Plugin.prototype;

  module.exports = InvitePlugin;
