const express = require("express");
const path = require("path");

const app = express();
const port = process.env.PORT || 3000; // Set a port for server listening

// Serve static files from the 'public' directory (for placeholder HTML)
app.use(express.static(path.join(__dirname, "frontend/build")));

// Serve video files from the 'storage' directory (placeholder)
app.all("/api/videoslist", (req, res) => {
  const data = express.static(path.join(__dirname, "storage"));
  res.send({
    data: "soemthing",
  });
  res.end();
}); // Adjust path if needed

app.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});
