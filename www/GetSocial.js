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

/// <summary>
/// Return GetSocial instance
/// </summary>
GetSocial.getInstance = function () {
    if (!this.instance) {
        this.instance = new GetSocial();
    }
    return this.instance;
}


/// <summary>
/// The method sets your app login data, it must be called before using any other functionality offered by the SDK.
/// </summary>
/// <param name="key">Your app's key, can be found in the GetSocial developer console</param>
/// <param name="onSuccess">Action called if operation was successful. Optional.</param>
/// <param name="onFailure">Action called if operation failed to complete. Optional.</param>
GetSocial.prototype.init = function(key, onSuccess, onFailure) {
    cordova.exec(onSuccess, onFailure, nativeBridgeName, "init", [key]);
}

/// <summary>
/// Returns the currently GetSocial initialization status.
/// </summary>
/// <value><c>true</c> if GetSocial is initialized; otherwise, <c>false</c>.</value>
GetSocial.prototype.isInitialized = function(onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "isInitialized", []);
}

/// <summary>
/// Returns the current SDK version
/// </summary>
/// <param name="onResult">Action called with version as argument.</param>
GetSocial.prototype.getVersion = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getVersion", []);
}
/// <summary>
/// Returns the current SDK APIversion
/// </summary>
/// <param name="onResult">Action called with apiversion as argument.</param>
GetSocial.prototype.getApiVersion = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getApiVersion", []);
}
/// <summary>
/// Returns the current Environment
/// </summary>
/// <param name="onResult">Action called with Environment as argument. Can <c>Android</c> or <c>iOS</c> </param>
GetSocial.prototype.getEnvironment = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getEnvironment", []);
}
/// <summary>
/// Returns all supported invite providers.
/// </summary>
/// <param name="onResult">Action called with array containing constants id's for all supported providers</returns>
GetSocial.prototype.getSupportedInviteProviders = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getSupportedInviteProviders", []);
}
/// <summary>
/// Returns configuration.
/// </summary>
/// <param name="onResult">Action called with null as argument.</param>
GetSocial.prototype.getConfiguration = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "getConfiguration", []);
}

/// <summary>
/// Provide a method that implements <c>OnReferralDataReceived</c> delegate if you would like to get referral data if the user installs or opens the app after opening a Smart Invite .
/// </summary>
/// <param name="onReferralDataReceived">Return refferalData in format [{key:value, key2:value2}, ...]</param>
GetSocial.prototype.setOnReferralDataReceivedListener = function (onReferralDataReceived) {
    cordova.exec(onReferralDataReceived, this.onErrorPlugin, nativeBridgeName, "setOnReferralDataReceivedListener", []);
}

/// <summary>
/// Sets the actions to be called when smart invites are triggered
/// </summary>
/// <param name="onInviteFriendsIntent">Action to be called when user clicked on specific invite provider.</param>
/// <param name="onFriendsInvited">Action to be called when user send invites. Gets number of invitations sent as a parameter.</param>
GetSocial.prototype.setOnInviteFriendsListener = function (onInviteFriendsIntent, onFriendsInvited ) {
        cordova.exec(function(jsonObj) {
            if(jsonObj != undefined) {
                if(jsonObj.Event == ON_INVITE_FRIENDS_INTENT_EVENT) {
                    onInviteFriendsIntent();
                } else if(jsonObj.Event == ON_INVITED_FRIENDS_EVENT) {
                    onFriendsInvited(jsonObj.InvitedFriends);
                }
            }
        }, this.onErrorPlugin, nativeBridgeName, "setOnInviteFriendsListener", []);
}
/// <summary>
/// Invite friends through a specific invite provider.
/// </summary>
/// <param name="provider">The provider through which the invite will be sent.</param>
/// <param name="subject">The subject to be sent with the invite. If it is null the default subject set on DevPortal is sent.</param>
/// <param name="text">The text to be sent with the invite. NOTE: you can use following tags to customize text: [APP_INVITE_URL] - tag is replaced with url to download the app; [APP_NAME] - tag is replaced with app name configured on the GetSocial Developer Portal. If it is null the default text set on DevPortal is sent.</param>
/// <param name="imageBase64">The image in base64 to be sent with the invite. If it is null the default image set on DevPortal will be sent.</param>
/// <param name="referralData">The bundle to be sent with the invite. It can be null.</param>
/// <param name="onResult">Action called when invoke inviteFriendsUsingProvider.</param>
GetSocial.prototype.inviteFriendsUsingProvider = function (provider, subject, text, imageBase64, referralData, onResult) {
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

        if(imageBase64 != null) {
           option.image = imageBase64;
        }

        if(referralData != null) {
           option.referrals = referralData;
        }

        cordova.exec(onResult, this.onErrorPlugin, nativeBridgeName, "inviteFriendsUsingProvider", [option]);
    }
/// <summary>
/// Register a new instance of a plugin for a specified provider.
/// </summary>
/// <param name="plugin">An instance of a plugin implementation</param>
/// <param name="onResult">Action called with callbackId as argument.</param>
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
module.exports.nativeBridgeName = nativeBridgeName; 
