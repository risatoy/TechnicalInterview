$(".square").each(function(){
  var square = this;
  $(this).click(function(){
    var id = $(this).attr("id");
    window.location.href = "/events/"+id;
  });
});
