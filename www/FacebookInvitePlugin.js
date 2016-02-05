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
 
    var scope = this;

    var showInviteFriendsDialog = function(subject, text, referralDataUrl, image) {
      facebookConnectPlugin.showDialog({
        method: "apprequests",
        link: referralDataUrl,
        caption: subject,
        message: text
      }, function(data) {
        if(data.request != null && (data.to != null && data.to.length > 0)) {
          scope.completeCallback(data.request, data.to);
        } else {
          scope.cancelCallback();
        }
      }, function(err) {
        console.log(JSON.stringify(data))
        if(err.errorCode != null && err.errorCode == 4201) {
          scope.cancelCallback();
        } else {
          onError(err.errorMessage)
        }
      })
    }

    var onError = function(err) {
      console.log(JSON.stringify(err))
      scope.errorCallback(err);
    }

    facebookConnectPlugin.getLoginStatus( function(userData) {
        if(userData.status !== "connected") {
          facebookConnectPlugin.login(["public_profile"],
             function() { showInviteFriendsDialog(subject, text, referralDataUrl, image) },
             onError
          );
        } else {
          showInviteFriendsDialog(subject, text, referralDataUrl, image);
        }
      }, onError);
  }

  FacebookInvitePlugin.prototype.__proto__ = InvitePlugin.prototype;

  module.exports = FacebookInvitePlugin;
