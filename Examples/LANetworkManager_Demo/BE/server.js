const express = require('express');
const app = express();
const port = 3000;

app.get('/check-update', (req, res) => {
    /* If some condition, updates available **/
    res.send("1"); 

    /* else res.send("0") -> updates not available **/

    /** You could also return json with res.json() */
});

app.listen(port, () => console.log(`BE listening on port ${port}`))


