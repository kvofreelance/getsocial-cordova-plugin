# Cordova Plugin for GetSocial SDK

### Install

`cordova plugins add https://github.com/kvofreelance/getsocial-cordova-plugin.git --variable APP_ID="<facebook_app_id>" --variable APP_NAME="<facebook_app_name>"`

Android

Modify MainActivity.java (src/"packageid"/MainActivity.java):
	
	import im.getsocial.sdk.core.GetSocial;

	...
	
	@Override
    protected void onResume() {
        super.onResume();
        GetSocial.getInstance(getApplicationContext()).onResume(this);
    }    
    
    @Override
    protected void onPause() {
        super.onPause();
        GetSocial.getInstance(getApplicationContext()).onPause();
    }

iOS
1. drag and drop the GetSocialChat.embeddedframework folder into your project navigator from Resources.
2. Add this flag -lstdc++ and -ObjC to your project’s “Other Linker Flags” inside Build Settings section.
