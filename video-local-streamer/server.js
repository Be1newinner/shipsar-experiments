const express = require("express");
const path = require("path");

const app = express();
const port = process.env.PORT || 3000; // Set a port for server listening

// Serve static files from the 'public' directory (for placeholder HTML)
app.use(express.static(path.join(__dirname, "public")));

// Serve video files from the 'storage' directory (placeholder)
app.use("/videos", express.static(path.join(__dirname, "storage"))); // Adjust path if needed

app.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});
