const net = require('net');

const server = net.createServer();

server.on('connection', (socket) => {
    console.log('Connection');
    // console.log(socket);

    socket.on('data', (data) => {
        console.log('Mensaje recibido: ', data.toString());
    });

    socket.on('error', (err) => console.log(err));
    socket.on('close', () => console.log('client has disconnected'));
});

server.on('error', (err) => console.log(err));

server.listen(4000, () => console.log('Server TCP on port: ', server.address().port));

