  var ViewBuilder = require('./ViewBuilder')

  var NATIVE_BRIDGE_NAME = "GetSocialCordova";

  var SmartInviteViewBuilder = function() {
    this.subject = null;
    this.text = null;
    this.referralData = null;
    this.image = null;
  }

    SmartInviteViewBuilder.prototype.setSubject = function(subject) {
      this.subject = subject;
      return this;
    }

    SmartInviteViewBuilder.prototype.setText = function(text) {
      this.text = text;
      return this;
    }

    SmartInviteViewBuilder.prototype.setReferralData = function(referralData) {
       this.referralData = referralData;
       return this;
    }

    // Need to fixed issue
    // SmartInviteViewBuilder.prototype.setImage = function(image) {
    //    this.image = image;
    //    return this;
    // }

    SmartInviteViewBuilder.prototype.show = function() {
      var option = {}
      if(this.subject != null) {
        option.subject = this.subject;
      }
      if(this.text != null) {
        option.text = this.text;
      }
      if(this.referralData != null) {
        option.referralData = this.referralData;
      }
      if(this.image != null) {
        option.image = this.image;
      }
      if(this.title != null) {
        option.title = this.title;
      }
      cordova.exec(null, null, NATIVE_BRIDGE_NAME, "createSmartInviteView", [option]);
    }

  SmartInviteViewBuilder.prototype.__proto__ = ViewBuilder.prototype;

  module.exports = SmartInviteViewBuilder;
