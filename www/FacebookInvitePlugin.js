  var InvitePlugin = require('./InvitePlugin')

  var FacebookInvitePlugin = function() {
    this.provider = "facebook";
  }

  FacebookInvitePlugin.prototype.getOptions = function() {
    var options = {}
    options.provider = this.provider;
    options.isAvailableForDevice = this.isAvailableForDevice();

    return options;
  }

  FacebookInvitePlugin.prototype.inviteFriends = function(subject, text, referralDataUrl, image) {
    //check if auth and run onComplete
    this.completeCallback("text", ['Hello', 'World'])
  }

  FacebookInvitePlugin.prototype.__proto__ = InvitePlugin.prototype;

  module.exports = FacebookInvitePlugin;
