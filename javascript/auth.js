const jwt = require("jsonwebtoken");
require('dotenv').config();
const User = require("../model/user");

const verifyToken = async (req, res, next) => {
  const authorizationHeader = req.headers.authorization;
  if (!authorizationHeader || !authorizationHeader.startsWith("Bearer ")) {
    return res.status(403).send("A valid Bearer token is required for authentication");
  }
  const token = authorizationHeader.split(" ")[1];
  try {
    const decoded = jwt.verify(token, process.env.TOKEN_KEY);
    const findUser = await User.find({ "email": decoded.email });
    if (findUser) {
        req.userEmail = findUser[0].email;
        next(); 
    } else {
      return res.status(401).send("Invalid Token");
    }
  } catch (err) {
    console.error(err); 
    return res.status(401).send("Invalid Token");
  }
};

module.exports = verifyToken;
