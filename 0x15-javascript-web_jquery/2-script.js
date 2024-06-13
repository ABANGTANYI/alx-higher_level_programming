// JavaScript code to update text color of header to red when the user clicks on div#red_header using jQuery
$(document).ready(function() {
  $('div#red_header').click(function() {
    $('header').css('color', '#FF0000');
  });
});
