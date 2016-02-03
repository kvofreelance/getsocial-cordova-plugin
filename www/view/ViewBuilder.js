  var ViewBuilder = function() {
    this.title;
  }

  ViewBuilder.prototype.setTitle = function(title) {
    this.title = title;
  }

  ViewBuilder.prototype.show = function() {
    //cordova.exec(successCallback, errorCallback, "GetSocialCordova", "inviteFriendsUsingProvider", [option]);
    console.log("This method is abstract");
  }

  module.exports = ViewBuilder;

