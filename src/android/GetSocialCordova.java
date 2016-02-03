package com.getsocialsdk.cordova.plugin;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Base64;
import android.util.Log;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import im.getsocial.sdk.core.GetSocial;
import im.getsocial.sdk.core.UI.builder.SmartInviteViewBuilder;
import im.getsocial.sdk.core.configuration.Configuration;

public class GetSocialCordova extends CordovaPlugin {
    private final String TAG = "GetSocialCordova_Plugin";

    private GetSocial mGetSocialImpl;

    public static Map<String, GetSocialPluginProxy> registeredPlugins;

    private final String INIT_METHOD = "init";
    private final String IS_INITIALIZED_METHOD = "isInitialized";
    private final String GET_VERSION_METHOD = "getVersion";
    private final String GET_API_VERSION_METHOD = "getApiVersion";
    private final String GET_ENVIROMENT_METHOD = "getEnvironment";
    private final String GET_CONFIGURATION_VERSION_METHOD = "getConfiguration";
    private final String SET_ON_INVITE_FRIENDS_LISTENER_METHOD = "setOnInviteFriendsListener";
    private final String SET_ON_REFERAL_DATA_RECEIVED_LISTENER_METHOD = "setOnReferralDataReceivedListener";
    private final String GET_SUPPORTED_INVITE_PROVIDERS_METHOD = "getSupportedInviteProviders";
    private final String INVITE_FRIENDS_USING_PROVIDER_METHOD = "inviteFriendsUsingProvider";
    private final String REGISTER_PLUGIN_METHOD = "registerPlugin";
    private final String CREATE_SMART_INVITE_VIEW_METHOD = "createSmartInviteView";

    private GetSocial getSocialImpl() {
        if(this.mGetSocialImpl == null) {
            this.mGetSocialImpl = GetSocial.getInstance(this.cordova.getActivity().getApplicationContext());
        }

        return this.mGetSocialImpl;
    }

    private void init(final String key, final CallbackContext callbackContext) {
        getSocialImpl().init(key, new GetSocial.OperationObserver()
                {
                    @Override
                    public void onSuccess(String data)
                    {
                        callbackContext.success(data);
                        Log.d(TAG, "GetSocial initialization successful");
                    }

                    @Override
                    public void onFailure()
                    {
                        callbackContext.error("GetSocial initialization failed");
                        Log.d(TAG, "GetSocial initialization failed");
                    }
                }
        );
    }
    private boolean isInitialized() {
        return getSocialImpl().isInitialized();
    }
    private String getVersion() {
        return GetSocial.VERSION;
    }
    private String getApiVersion() {
        return GetSocial.API;
    }
    private String getEnvironment() {
        return "Android";
    }
    private Configuration getConfiguration() {
        return getSocialImpl().getConfiguration();
    }
    private void setOnInviteFriendsListener(final CallbackContext callbackContext) {
        getSocialImpl().setInviteFriendsListener(new GetSocial.InviteFriendsListener() {
            private final int ON_INVITE_FRIENDS_INTENT_EVENT = 0;
            private final int ON_INVITED_FRIENDS_EVENT = 1;
            @Override
            public void onInviteFriendsIntent() {
                JSONObject obj = new JSONObject();
                try {
                    obj.put("Event", ON_INVITE_FRIENDS_INTENT_EVENT);
                } catch (Exception e) {}
                sentResult(obj);
            }

            @Override
            public void onInvitedFriends(int i) {
                JSONObject obj = new JSONObject();
                try {
                    obj.put("Event", ON_INVITED_FRIENDS_EVENT);
                    obj.put("InvitedFriends", i);
                } catch (Exception e) {}
                sentResult(obj);
            }

            public void sentResult(JSONObject obj) {
                PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, obj);
                pluginResult.setKeepCallback(true);
                callbackContext.sendPluginResult(pluginResult);
            }
        });
    }
    private void setOnReferralDataReceivedListener(final CallbackContext callbackContext) {
        getSocialImpl().setOnReferralDataReceivedListener(new GetSocial.OnReferralDataReceivedListener() {
            @Override
            public void onReferralDataReceived(List<Map<String, String>> list) {
                JSONArray resultArray = new JSONArray();

                for (int i = 0; i < list.size(); i++) {
                    Map<String, String> entries = list.get(i);
                    JSONArray array = new JSONArray();
                    for (Map.Entry<String, String> entry : entries.entrySet()) {
                        try {
                            JSONObject obj = new JSONObject();
                            obj.put(entry.getKey(), entry.getValue());
                            array.put(obj);
                        } catch (Exception e) {
                        }
                    }

                    resultArray.put(array);
                }

                PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, resultArray);
                pluginResult.setKeepCallback(true);
                callbackContext.sendPluginResult(pluginResult);
            }
        });
    }
    private String[] getSupportedInviteProviders() {
        return getSocialImpl().getSupportedInviteProviders();
    }
    private boolean inviteFriendsUsingProvider(JSONObject option) {
        if(option == null)
            return false;

        String provider = option.optString("provider");
        if(provider.isEmpty())
            return false;

        String subject = option.optString("subject");
        if(subject.isEmpty())
            subject=null;

        String text = option.optString("text");
        if(text.isEmpty())
            text=null;

        Bitmap image = null;
        String imageBase64 = option.optString("image");
        if(!imageBase64.isEmpty()) {
            if(imageBase64.indexOf(",") >-1) {
                int position = imageBase64.indexOf(",")+1;
                imageBase64 = imageBase64.substring(position, imageBase64.length() - position);
            }
            byte[] decodedString = Base64.decode(imageBase64, Base64.DEFAULT);
            image = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
        }

        Map<String,String> referralData = null;
        JSONArray referralsArray = option.optJSONArray("referrals");
        if(referralsArray != null) {
            referralData = new HashMap<String, String>();
            for(int i=0; i< referralsArray.length(); i++) {
                JSONObject obj = referralsArray.optJSONObject(0);
                if(obj != null) {
                    Iterator<String> keysItr = obj.keys();
                    while(keysItr.hasNext()) {
                        String key = keysItr.next();
                        String value = obj.optString(key);

                        referralData.put(key, value);
                    }
                }
            }
        }

        getSocialImpl().inviteFriendsUsingProvider(provider, subject, text, image, referralData);

        return true;
    }

    private void registerPlugin(JSONObject pluginOptions, CallbackContext callbackContext) {
        boolean isAvailableForDevice = pluginOptions.optBoolean("isAvailableForDevice");
        String provider = pluginOptions.optString("provider");

        GetSocialPluginProxy getSocialPluginProxy = new GetSocialPluginProxy(callbackContext, isAvailableForDevice);
        getSocialImpl().registerPlugin(provider, getSocialPluginProxy);

        if(GetSocialCordova.registeredPlugins == null)
            GetSocialCordova.registeredPlugins = new HashMap<String, GetSocialPluginProxy>();

        registeredPlugins.put(callbackContext.getCallbackId(), getSocialPluginProxy);

        getSocialPluginProxy.initCallbackId(callbackContext.getCallbackId());
    }

    private boolean createSmartInviteView(JSONObject option) {
        if(option == null)
            return false;

        SmartInviteViewBuilder smartInviteViewBuilder = getSocialImpl().createSmartInviteView();

        String subject = option.optString("subject");
        if(!subject.isEmpty())
            smartInviteViewBuilder.setSubject(subject);

        String text = option.optString("text");
        if(!text.isEmpty())
            smartInviteViewBuilder.setText(text);

        String title = option.optString("title");
        if(!title.isEmpty())
            smartInviteViewBuilder.setTitle(title);

        String imageUrlString = option.optString("image");
        if(!imageUrlString.isEmpty())
            smartInviteViewBuilder.setImageUrl(imageUrlString);

        Map<String,String> referralData = getMapFromJSONArray(option.optJSONArray("referralData"));
        if(referralData != null)
            smartInviteViewBuilder.setReferralData(referralData);

        smartInviteViewBuilder.show();

        return true;
    }


    private Map<String, String> getMapFromJSONArray(JSONArray array) {
        Map<String,String> referralData = null;
        if(array != null) {
            referralData = new HashMap<String, String>();
            for(int i=0; i< array.length(); i++) {
                JSONObject obj = array.optJSONObject(0);
                if(obj != null) {
                    Iterator<String> keysItr = obj.keys();
                    while(keysItr.hasNext()) {
                        String key = keysItr.next();
                        String value = obj.optString(key);

                        referralData.put(key, value);
                    }
                }
            }
        }

        return referralData;
    }


    @Override
    public boolean execute(String action, JSONArray data, CallbackContext callbackContext) throws JSONException {
        if(action.equalsIgnoreCase(REGISTER_PLUGIN_METHOD)) {
            if(data.length() != 1)
                return false;

            registerPlugin(data.getJSONObject(0), callbackContext);
            return true;
        }

        if(action.equals(CREATE_SMART_INVITE_VIEW_METHOD)) {
            if(data.length() == 0) {
                return false;
            }
            return createSmartInviteView(data.getJSONObject(0));
        }

        if(action.equals(INVITE_FRIENDS_USING_PROVIDER_METHOD)) {
            if(data.length() == 0) {
                return false;
            }

            return inviteFriendsUsingProvider(data.getJSONObject(0));
        }

        if(action.equals(GET_SUPPORTED_INVITE_PROVIDERS_METHOD)) {
            JSONArray resultArray = new JSONArray();
            for (String item:getSupportedInviteProviders()) {
                resultArray.put(item);
            }
            callbackContext.success(resultArray);

            return true;
        }

        if(action.equals(SET_ON_REFERAL_DATA_RECEIVED_LISTENER_METHOD)) {
            setOnReferralDataReceivedListener(callbackContext);

            return true;
        }

        if(action.equals(SET_ON_INVITE_FRIENDS_LISTENER_METHOD)) {
            setOnInviteFriendsListener(callbackContext);

            return true;
        }

        if(action.equals(INIT_METHOD)) {
            final String key = data.getString(0);
            init(key, callbackContext);

            return true;
        }

        if(action.equals(IS_INITIALIZED_METHOD)) {
            callbackContext.success(isInitialized() ? 1:0);

            return true;
        }

        if(action.equals(GET_VERSION_METHOD)) {
            callbackContext.success(getVersion());

            return true;
        }

        if(action.equals(GET_API_VERSION_METHOD)) {
            callbackContext.success(getApiVersion());

            return true;
        }

        if(action.equals(GET_ENVIROMENT_METHOD)) {
            callbackContext.success(getEnvironment());

            return true;
        }

        if(action.equals(GET_CONFIGURATION_VERSION_METHOD)) {
            // Need to check. Crash on click
            Configuration config = getConfiguration();
            callbackContext.success("");

            return true;
        }

        return false;
    }
}