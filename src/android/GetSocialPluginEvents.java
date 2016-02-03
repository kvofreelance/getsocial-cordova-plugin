package com.getsocialsdk.cordova.plugin;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by bevzhome on 03.02.16.
 */
public class GetSocialPluginEvents extends CordovaPlugin {
    private final String COMPLETE_CALLBACK_METHOD = "completeCallback";
    private final String CANCEL_CALLBACK_METHOD = "cancelCallback";
    private final String ERROR_CALLBACK_METHOD = "errorCallback";
    private final String CLICKED_CALLBACK_METHOD = "clickedCallback";

    private GetSocialPluginProxy getSocialPluginProxy(String callbackId) {
        if(GetSocialCordova.registeredPlugins == null)
            return null;

        if(!GetSocialCordova.registeredPlugins.containsKey(callbackId))
            return null;

        return GetSocialCordova.registeredPlugins.get(callbackId);
    }
    @Override
    public boolean execute(String action, JSONArray data, CallbackContext callbackContext) throws JSONException {
        if(data.length() == 0)
            return false;

        if (action.equalsIgnoreCase(COMPLETE_CALLBACK_METHOD)) {
            GetSocialPluginProxy plugin = getSocialPluginProxy(data.getString(0));
            if(plugin == null)
                return false;

            if(data.length() != 3)
                return false;

            JSONArray array = data.optJSONArray(2);
            List<String> list = new ArrayList<String>();
            for (int i=0; i < array.length(); i++) {
                list.add(array.optString(i));
            }

            return plugin.onComplete(data.optString(1), list);
        }
        if (action.equalsIgnoreCase(CANCEL_CALLBACK_METHOD)) {
            GetSocialPluginProxy plugin = getSocialPluginProxy(data.getString(0));
            if(plugin == null)
                return false;

            return plugin.onCancel();
        }
        if (action.equalsIgnoreCase(ERROR_CALLBACK_METHOD)) {
            GetSocialPluginProxy plugin = getSocialPluginProxy(data.getString(0));
            if(plugin == null)
                return false;

            return plugin.onError();
        }
        if (action.equalsIgnoreCase(CLICKED_CALLBACK_METHOD)) {
            GetSocialPluginProxy plugin = getSocialPluginProxy(data.getString(0));
            if(plugin == null)
                return false;

            return plugin.onClicked();
        }
        return false;
    }
}