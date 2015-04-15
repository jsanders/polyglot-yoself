r = require('rethinkdb');
r.connect({ host: 'localhost', port: 28015 }, function(err, conn) {
  if(err) throw err;
  r.db('test').tableCreate('users').run(conn, function(err, res) {
    if(err) throw err;
    console.log(res);
    r.table('users').insert({ first_name: 'James', last_name: 'Sanders' }).run(conn, function(err, res) {
      if(err) throw err;
      console.log(res);
    });
  });
});
