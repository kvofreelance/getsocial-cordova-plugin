package com.getsocialsdk.cordova.plugin;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

import im.getsocial.sdk.core.GetSocial;

/**
 * Created by bevzhome on 03.02.16.
 */
public class GetSocialConfiguration extends CordovaPlugin {
    private final String SET_CONFIGURATION_METHOD = "setConfiguration";
    private final String CLEAR_METHOD = "clear";
    private final String BEGIN_TANSACTION_METHOD = "beginTransaction";
    private final String END_TANSACTION_METHOD = "endTransaction";
    private final String SET_BASE_PATH_METHOD = "setBasePath";
    private final String SET_IMAGE_PATH_METHOD = "setImagePath";
    private final String SET_BASE_DESIGN_METHOD = "setBaseDesign";
    private final String SET_DIMENSION_METHOD = "setDimension";
    private final String SET_ASPECT_RATIO_METHOD = "setAspectRatio";
    private final String SET_TEXT_STYLE_METHOD = "setTextStyle";
    private final String SET_ANIMATION_STYLE_METHOD = "setAnimationStyle";
    private final String SET_INSETS_METHOD = "setInsets";

    private void setConfiguration(String fileOrUrl) {
        GetSocial.getConfiguration().setConfiguration(fileOrUrl);
    }

    private void clear() {
        GetSocial.getConfiguration().clear();
    }

    private void beginTransaction() {
        GetSocial.getConfiguration().beginTransaction();
    }

    private void endTransaction() {
        GetSocial.getConfiguration().endTransaction();
    }

    private void setBasePath(String baseAssetsPath) {
        GetSocial.getConfiguration().setBasePath(baseAssetsPath);
    }

    private void setImagePath(String id, String path) {
        GetSocial.getConfiguration().setImagePath(id, path);
    }

    private void setBaseDesign(int width, int height, int ppi, String scaleMode) {
        GetSocial.getConfiguration().setBaseDesign(width, height, ppi, scaleMode);
    }

    private void setDimension(String id, int dimension) {
        GetSocial.getConfiguration().setDimension(id, dimension);
    }

    private void setAspectRatio(String id, float aspectRatio) {
        GetSocial.getConfiguration().setAspectRatio(id, aspectRatio);
    }

    private void setTextStyle(String id, String typefacePath, float textSize, int textColor, int strokeColor, float strokeSize, float strokeXOffset, float strokeYOffset) {
        GetSocial.getConfiguration().setTextStyle(id, typefacePath, textSize, textColor, strokeColor, strokeSize, strokeXOffset, strokeYOffset);
    }

    private void setAnimationStyle(String id, int animationStyle) {
        GetSocial.getConfiguration().setAnimationStyle(id, animationStyle);
    }

    private void setInsets(String id, int top, int right, int bottom, int left) {
        GetSocial.getConfiguration().setInsets(id, top, right, bottom, left);
    }


    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {

        if(action.equalsIgnoreCase(SET_CONFIGURATION_METHOD)) {
            if(args.length() != 1)
                return false;

            setConfiguration(args.optString(0));
            return true;
        }

        if(action.equalsIgnoreCase(CLEAR_METHOD)) {
            clear();
            return true;
        }

        if(action.equalsIgnoreCase(BEGIN_TANSACTION_METHOD)) {
            beginTransaction();
            return true;
        }

        if(action.equalsIgnoreCase(END_TANSACTION_METHOD)) {
            endTransaction();
            return true;
        }

        if(action.equalsIgnoreCase(SET_BASE_PATH_METHOD)) {
            if(args.length() != 1)
                return false;

            setBasePath(args.optString(0));
            return true;
        }

        if(action.equalsIgnoreCase(SET_IMAGE_PATH_METHOD)) {
            if(args.length() != 2)
                return false;

            setImagePath(args.optString(0), args.optString(1));
            return true;
        }

        if(action.equalsIgnoreCase(SET_BASE_DESIGN_METHOD)) {
            if(args.length() != 4)
                return false;

            setBaseDesign(args.optInt(0), args.optInt(1), args.optInt(2), args.optString(3));
            return true;
        }

        if(action.equalsIgnoreCase(SET_DIMENSION_METHOD)) {
            if(args.length() != 2)
                return false;

            setDimension(args.optString(0), args.optInt(1));
            return true;
        }

        if(action.equalsIgnoreCase(SET_ASPECT_RATIO_METHOD)) {
            if(args.length() != 2)
                return false;

            setAspectRatio(args.optString(0), (float) args.optDouble(1));
            return true;
        }

        if(action.equalsIgnoreCase(SET_TEXT_STYLE_METHOD)) {
            if(args.length() != 8)
                return false;

            setTextStyle(args.optString(0), args.optString(1), (float) args.optDouble(2), args.optInt(3), args.optInt(4), (float) args.optDouble(5), (float) args.optDouble(6), (float) args.optDouble(7));
            return true;
        }

        if(action.equalsIgnoreCase(SET_ANIMATION_STYLE_METHOD)) {
            if(args.length() != 2)
                return false;

            setAnimationStyle(args.optString(0), args.optInt(1));
            return true;
        }

        if(action.equalsIgnoreCase(SET_INSETS_METHOD)) {
            if(args.length() != 2)
                return false;

            setInsets(args.optString(0), args.optInt(1), args.optInt(2), args.optInt(3), args.optInt(4));
            return true;
        }

        return false;
    }
}
