var faker = require('faker');
var r = require('rethinkdb');
r.connect({ host: 'localhost', port: 28015 }, function(err, conn) {
  if(err) throw err;
  var users = r.table('users');
  users.changes().run(conn, function(err, cursor) {
    if (err) throw err;
    cursor.each(function(err, row) {
      if (err) throw err;
      console.log("New user: " + JSON.stringify(row, null, 2));
    });
  });
  setInterval(function() {
    users.insert({ first_name: faker.name.firstName(), last_name: faker.name.lastName() }).run(conn, function(err, res) {
      if(err) throw err;
      console.log(res);
    });
  }, 1000);
});
