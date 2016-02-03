# Cordova Plugin for GetSocial SDK

### Install

`cordova plugins add https://github.com/kvofreelance/getsocial-cordova-plugin.git --variable FACEBOOK_APP_ID="<facebook_app_id>"`

Modify MainActivity.java (src/<packageid>/MainActivity.java)

`@Override
    protected void onResume() {
        super.onResume();
        GetSocial.getInstance(getApplicationContext()).onResume(this);
    }

    @Override
    protected void onPause() {
        super.onPause();
        GetSocial.getInstance(getApplicationContext()).onPause();
    }
`