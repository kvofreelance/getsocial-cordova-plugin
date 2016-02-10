package com.getsocialsdk.cordova.plugin;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Base64;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.ContentHandler;
import java.nio.ByteBuffer;

/**
 * Created by bevzhome on 03.02.16.
 */
public class GetSocialUtil {

    public static String convertBitmapToBase64(Bitmap bitmap) {
        final int size =bitmap.getByteCount();

        ByteBuffer dst= ByteBuffer.allocate(size);
        bitmap.copyPixelsToBuffer(dst);
        return Base64.encodeToString(dst.array(), Base64.DEFAULT);
    }

    public static Bitmap getImageFromGetSocialPluginParam(Context ctx, String data) {
        if (data == null) return null;

        try {

            InputStream image = ctx.getAssets().open(data);
            if(image != null) {
                // It's path to file
                return BitmapFactory.decodeStream(image);
            }
        } catch (IOException e) {}

        // It's base64 input data
        if(data.indexOf(",") >-1) {
            int position = data.indexOf(",")+1;
            data = data.substring(position, data.length() - position);
        }
        byte[] decodedString = Base64.decode(data, Base64.DEFAULT);
        return BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
    }
}
