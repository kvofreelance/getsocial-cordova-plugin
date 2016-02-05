package com.getsocialsdk.cordova.plugin;

import android.content.Context;
import android.graphics.Bitmap;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.json.JSONObject;

import java.util.List;

import im.getsocial.sdk.core.plugins.InvitePlugin;

/**
 * Created by bevzhome on 03.02.16.
 */
public class GetSocialPluginProxy extends InvitePlugin {
    private CallbackContext callbackContext;
    boolean isAvailableForDevice = false;
    InviteFriendsObserver inviteFriendsObserver = null;

    public GetSocialPluginProxy(CallbackContext callbackContext, boolean isAvailableForDevice) {
        this.callbackContext = callbackContext;
        this.isAvailableForDevice = isAvailableForDevice;
    }

    public boolean onComplete(String s, List<String> list) {
        if (inviteFriendsObserver == null)
            return false;

        inviteFriendsObserver.onComplete(s, list);

        return true;
    }

    public boolean onCancel() {
        if (inviteFriendsObserver == null)
            return false;

        inviteFriendsObserver.onCancel();

        return true;
    }

    public boolean onError() {
        if (inviteFriendsObserver == null)
            return false;

        inviteFriendsObserver.onError(new Exception());

        return true;
    }
    public boolean onClicked() {
        if (inviteFriendsObserver == null)
            return false;

        inviteFriendsObserver.onClicked();

        return true;
    }

    @Override
    public void inviteFriends(Context context, String s, String s1, String s2, Bitmap bitmap, InviteFriendsObserver inviteFriendsObserver) {
        this.inviteFriendsObserver = inviteFriendsObserver;

        JSONObject result = new JSONObject();
        try {
            result.put("action", "inviteFriends");
            result.put("subject", s);
            result.put("text", s1);
            result.put("referralDataUrl", s2);
            result.put("image", GetSocialUtil.convertBitmapToBase64(bitmap));
        } catch (Exception e) {}

        PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, result);
        pluginResult.setKeepCallback(true);
        callbackContext.sendPluginResult(pluginResult);
    }

    public void emulateInviteFriends() {
        JSONObject result = new JSONObject();
        try {
            result.put("action", "inviteFriends");
            result.put("s1", "subject");
        } catch (Exception e) {}

        PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, result);
        pluginResult.setKeepCallback(true);
        callbackContext.sendPluginResult(pluginResult);
    }

    public void initCallbackId(String callbackId) {
        JSONObject result = new JSONObject();
        try {
            result.put("action", "initCallbackId");
            result.put("callbackId", callbackId);
        } catch (Exception e) {}

        PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, result);
        pluginResult.setKeepCallback(true);
        callbackContext.sendPluginResult(pluginResult);
    }

    @Override
    public boolean isAvailableForDevice(Context context) {
        return isAvailableForDevice;
    }


}
