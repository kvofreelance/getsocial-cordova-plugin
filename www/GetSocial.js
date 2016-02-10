/*global cordova, module*/
var SmartInviteViewBuilder = require('./SmartInviteViewBuilder')

var NATIVE_BRIDGE_NAME = "GetSocialCordova";

var INVITE_FRIENDS_EVENTS = {
    ON_INVITE_FRIENDS_INTENT_EVENT: 0,
    ON_INVITED_FRIENDS_EVENT: 1
}

var PLUGIN_EVENT = {
    INVITE_FRIENDS: "inviteFriends",
    INIT_CALLBACK_ID: "initCallbackId"
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
    cordova.exec(onSuccess, onFailure, NATIVE_BRIDGE_NAME, "init", [key]);
}

/// <summary>
/// Returns the currently GetSocial initialization status.
/// </summary>
/// <value><c>true</c> if GetSocial is initialized; otherwise, <c>false</c>.</value>
GetSocial.prototype.isInitialized = function(onResult) {
    cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "isInitialized", []);
}

/// <summary>
/// Returns the current SDK version
/// </summary>
/// <param name="onResult">Action called with version as argument.</param>
GetSocial.prototype.getVersion = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "getVersion", []);
}
/// <summary>
/// Returns the current SDK APIversion
/// </summary>
/// <param name="onResult">Action called with apiversion as argument.</param>
GetSocial.prototype.getApiVersion = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "getApiVersion", []);
}
/// <summary>
/// Returns the current Environment
/// </summary>
/// <param name="onResult">Action called with Environment as argument. Can <c>Android</c> or <c>iOS</c> </param>
GetSocial.prototype.getEnvironment = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "getEnvironment", []);
}
/// <summary>
/// Returns all supported invite providers.
/// </summary>
/// <param name="onResult">Action called with array containing constants id's for all supported providers</returns>
GetSocial.prototype.getSupportedInviteProviders = function (onResult) {
    cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "getSupportedInviteProviders", []);
}
// /// <summary>
// /// Returns configuration.
// /// </summary>
// /// <param name="onResult">Action called with null as argument.</param>
// GetSocial.prototype.getConfiguration = function (onResult) {
//     cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "getConfiguration", []);
// }

/// <summary>
/// Provide a method that implements <c>OnReferralDataReceived</c> delegate if you would like to get referral data if the user installs or opens the app after opening a Smart Invite .
/// </summary>
/// <param name="onReferralDataReceived">Return refferalData in format [{key:value, key2:value2}, ...]</param>
GetSocial.prototype.setOnReferralDataReceivedListener = function (onReferralDataReceived) {
    cordova.exec(onReferralDataReceived, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "setOnReferralDataReceivedListener", []);
}

/// <summary>
/// Sets the actions to be called when smart invites are triggered
/// </summary>
/// <param name="onInviteFriendsIntent">Action to be called when user clicked on specific invite provider.</param>
/// <param name="onFriendsInvited">Action to be called when user send invites. Gets number of invitations sent as a parameter.</param>
GetSocial.prototype.setOnInviteFriendsListener = function (onInviteFriendsIntent, onFriendsInvited ) {
        cordova.exec(function(jsonObj) {
            if(jsonObj != undefined) {
                if(jsonObj.Event == INVITE_FRIENDS_EVENTS.ON_INVITE_FRIENDS_INTENT_EVENT) {
                    onInviteFriendsIntent();
                } else if(jsonObj.Event == INVITE_FRIENDS_EVENTS.ON_INVITED_FRIENDS_EVENT) {
                    onFriendsInvited(jsonObj.InvitedFriends);
                }
            }
        }, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "setOnInviteFriendsListener", []);
}
/// <summary>
/// Invite friends through a specific invite provider.
/// </summary>
/// <param name="provider">The provider through which the invite will be sent.</param>
/// <param name="subject">The subject to be sent with the invite. If it is null the default subject set on DevPortal is sent.</param>
/// <param name="text">The text to be sent with the invite. NOTE: you can use following tags to customize text: [APP_INVITE_URL] - tag is replaced with url to download the app; [APP_NAME] - tag is replaced with app name configured on the GetSocial Developer Portal. If it is null the default text set on DevPortal is sent.</param>
/// <param name="image">The image in base64 to be sent with the invite or path to image in assets catalog. If it is null the default image set on DevPortal will be sent.</param>
/// <param name="referralData">The bundle to be sent with the invite. It can be null.</param>
/// <param name="onResult">Action called when invoke inviteFriendsUsingProvider.</param>
GetSocial.prototype.inviteFriendsUsingProvider = function (provider, subject, text, image, referralData, onResult) {
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

        cordova.exec(onResult, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "inviteFriendsUsingProvider", [option]);
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

        if (action === PLUGIN_EVENT.INIT_CALLBACK_ID) {
            plugin.setCallbackId(data.callbackId)
            onResult(data.callbackId);
        }
        if(action === PLUGIN_EVENT.INVITE_FRIENDS) {
            var subject = data.subject;
            var text = data.text;
            var referralDataUrl = data.referralDataUrl;
            var image = data.image;
            plugin.inviteFriends(subject, text, referralDataUrl, image);
        }

    }, this.onErrorPlugin, NATIVE_BRIDGE_NAME, "registerPlugin", [plugin.getOptions()]);
}
module.exports = GetSocial;
