package com.getsocialsdk.cordova.plugin;

import android.graphics.Bitmap;
import android.util.Base64;

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
}
