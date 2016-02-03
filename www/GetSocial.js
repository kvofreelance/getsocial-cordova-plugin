/*global cordova, module*/
var SmartInviteViewBuilder = require('./SmartInviteViewBuilder')

var nativeBridgeName = "GetSocialCordova";
var constants = {
    ON_INVITE_FRIENDS_INTENT_EVENT: 0,
    ON_INVITED_FRIENDS_EVENT: 1
}

var PluginEvent = {
    INVITE_FRIENDS: "inviteFriends",
    INIT_CALLBACK_ID: "initCallbackId"
}
var ScaleMode = {
    ScaleWithScreenSize: 1
}

var AnimationStyle = {
    None: 0,
    Scale: 1,
    Fade: 2,
    FadeAndScale: 3
}

var GetSocial = function() {

    this.instance = null;

    this.onErrorPlugin = function(err) {
        console.log(err);
    }
}

GetSocial.getInstance = function () {
    if (!this.instance) {
        this.instance = new GetSocial();
    }
    return this.instance;
}

GetSocial.prototype.init = function(key, onSuccess, onFailure) {
    cordova.exec(onSuccess, onFailure, nativeBridgeName, "init", [key]);
}

GetSocial.prototype.isInitialized = function(onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "isInitialized", []);
}

GetSocial.prototype.getVersion = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getVersion", []);
}
GetSocial.prototype.getApiVersion = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getApiVersion", []);
}
GetSocial.prototype.getEnvironment = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getEnvironment", []);
}
GetSocial.prototype.getSupportedInviteProviders = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getSupportedInviteProviders", []);
}
GetSocial.prototype.getConfiguration = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getConfiguration", []);
}
GetSocial.prototype.setOnReferralDataReceivedListener = function (onReferralDataReceivedListener) {
    cordova.exec(onReferralDataReceivedListener, this.onErrorPlugin, nativeBridgeName, "setOnReferralDataReceivedListener", []);
}
GetSocial.prototype.setOnInviteFriendsListener = function (onInviteFriendsIntentCallback, onInvitedFriendsCallback ) {
        cordova.exec(function(jsonObj) {
            if(jsonObj != undefined) {
                if(jsonObj.Event == ON_INVITE_FRIENDS_INTENT_EVENT) {
                    onInviteFriendsIntentCallback();
                } else if(jsonObj.Event == ON_INVITED_FRIENDS_EVENT) {
                    onInvitedFriendsCallback(jsonObj.InvitedFriends);
                }
            }
        }, this.onErrorPlugin, nativeBridgeName, "setOnInviteFriendsListener", []);
}
GetSocial.prototype.inviteFriendsUsingProvider = function (provider, subject, text, image, referralData, onInvokeStatus) {
        var option = {}
        if(provider == null) {
            errorCallback("Please set provider value");
            return
        }
        option.provider = provider;

        if(subject != null) {
            option.subject = subject;
        }
        if(text != null) {
           option.text = text;
        }

        if(image != null) {
           option.image = image;
        }

        if(referralData != null) {
           option.referrals = referralData;
        }

        cordova.exec(onInvokeStatus, this.onErrorPlugin, nativeBridgeName, "inviteFriendsUsingProvider", [option]);
    }

GetSocial.prototype.registerPlugin = function (onResult, plugin) {
    if (!(plugin instanceof InvitePlugin))
        return false;

    cordova.exec(function(data) {
        var action = data.action;
        if(action == null)
            return;

        if (action === PluginEvent.INIT_CALLBACK_ID) {
            plugin.setCallbackId(data.callbackId)
            onResult(data.callbackId);
        }
        if(action === PluginEvent.INVITE_FRIENDS) {
            var s = data.s;
            var s1 = data.s1;
            var s2 = data.s2;
            var image = data.image;
            plugin.inviteFriends(s, s1, s2, image);
        }

    }, this.onErrorPlugin, nativeBridgeName, "registerPlugin", [plugin.getOptions()]);
}
module.exports = GetSocial;
module.exports.ScaleMode = ScaleMode;
module.exports.AnimationStyle = AnimationStyle;
