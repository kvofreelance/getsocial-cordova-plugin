  var GetSocial = require('./GetSocial')

  var nativeBridgeName = "GetSocialConfiguration"
  var Configuration = function() {}

  var Configuration = function() {
      this.instance = null;

      this.onSuccess = function() {}
      this.onErrorPlugin = function(err) {
          console.log(err);
      }
  }

  Configuration.getInstance = function () {
      if (!this.instance) {
          this.instance = new Configuration();
      }
      return this.instance;
  }

  Configuration.prototype.setConfiguration = function(fileOrUrl) {
    if(fileOrUrl == null || fileOrUrl == "") {
        console.log("Configuration path is null or empty");
        return;
    }

    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setConfiguration", [fileOrUrl]);
  }

  Configuration.prototype.clear = function() {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "clear", []);
  }

  Configuration.prototype.beginTransaction = function() {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "beginTransaction", []);
  }
  Configuration.prototype.endTransaction = function() {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "endTransaction", []);
  }
  Configuration.prototype.setBasePath = function(baseAssetsPath) {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setBasePath", [baseAssetsPath]);
  }
  Configuration.prototype.setImagePath = function(id, path) {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setImagePath", [id, path]);
  }
  Configuration.prototype.setBaseDesign = function(width, height, ppi, scaleMode) {
    var scaleModeString = "";
    switch(scaleMode) {
       case GetSocial.ScaleMode.ScaleWithScreenSize:
          scaleModeString = "scale-with-screen-size";
          break;

       default:
          console.log("Specified scale mode is not valid");
          scaleModeString = "scale-with-screen-size";
          break;
    }
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setBaseDesign", [width, height, ppi, scaleModeString]);
  }
  Configuration.prototype.setDimension = function(id, dimension) {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setDimension", [id, dimension]);
  }
  Configuration.prototype.setAspectRatio = function(id, aspectRatio) {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setAspectRatio", [id, aspectRatio]);
  }
  Configuration.prototype.setTextStyle = function(id, typefacePath, textSize, textColor, strokeColor, strokeSize, strokeXOffset, strokeYOffset) {
    var mStrokeColor = 0
    if(strokeColor != null) {
        mStrokeColor = strokeColor
    }
    var mStrokeSize = 0
    if(strokeSize != null) {
        mStrokeSize = strokeSize
    }
    var mStrokeXOffset = 0
    if(strokeXOffset != null) {
        mStrokeXOffset = strokeXOffset
    }
    var mStrokeYOffset = 0
    if(strokeYOffset != null) {
        mStrokeYOffset = strokeYOffset
    }
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setTextStyle", [id, typefacePath, textSize, textColor, mStrokeColor, mStrokeSize, mStrokeXOffset, mStrokeYOffset]);
  }
  Configuration.prototype.setAnimationStyle = function(id, animationStyle) {
    var animationStyleResult = -1;
    for (var k in GetSocial.AnimationStyle) {
      if (!GetSocial.AnimationStyle.hasOwnProperty(k)) continue;
      if (GetSocial.AnimationStyle[k] === animationStyle) {
        animationStyleResult = animationStyle
      }
    }
    if(animationStyle == -1) {
        console.log("Wrong animationStyle value");
        return;
    }

    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setAnimationStyle", [id, animationStyle]);
  }
  Configuration.prototype.setInsets = function( id, top, right, bottom, left) {
    cordova.exec(this.onSuccess, this.onFailure, nativeBridgeName, "setInsets", [id, top, right, bottom, left]);
  }

  module.exports = Configuration;
