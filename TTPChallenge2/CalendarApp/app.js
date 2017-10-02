var express    = require("express"),
    app        = express(),
    mongoose   = require("mongoose"),
    bodyParser = require("body-parser");

mongoose.connect("mongodb://localhost/calendar_app");
app.set("view engine", "ejs");
app.use(express.static(__dirname + "/public"));   //link to public directory
app.use(bodyParser.urlencoded({extended: true}));

//SCHEMA
var calendarSchema = new mongoose.Schema({
  date: Number,
  starttime: String,
  endtime: String,
  description: String
});

var Calendar = mongoose.model("Calendar", calendarSchema);

app.get("/", function(req, res){
  Calendar.find({}, function(err, allCalendars){
    if (err){
      console.log(err);
    } else {
      res.render("index", {calendars: allCalendars});
    }
  })
});
app.post("/", function(req, res){
  var date = req.body.date.substring(8);
  var starttime = req.body.starttime;
  var endtime = req.body.endtime;
  var desc = req.body.desc;
  var newCalender = {date:date, starttime: starttime, endtime: endtime, description: desc}

  Calendar.create(newCalender, function(err, newlyCreated){
    if (err){
      console.log(err);
    } else {
      res.redirect("/");
    }
  });


  //console.log(starttime + " and " + endtime +" " + desc);
});

app.get("/events/:id", function(req, res) {
  res.render("eventform");
});

app.listen(7000, function(){
  console.log("server has started...")
});
