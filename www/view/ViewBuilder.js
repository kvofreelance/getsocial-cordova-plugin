  var ViewBuilder = function() {
    this.title;
  }

  ViewBuilder.prototype.setTitle = function(title) {
    this.title = title;
    return this;
  }

  ViewBuilder.prototype.show = function() {
    console.log("This method is abstract");
  }

  module.exports = ViewBuilder;

