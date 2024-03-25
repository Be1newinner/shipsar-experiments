import React, { useState, useEffect } from "react";
import VideoPlayer from "./VideoPlayer";
import VideoList from "./VideoList";

const App = () => {
  const [videos, setVideos] = useState([]);
  const [selectedVideo, setSelectedVideo] = useState({
    url: "tom-jerry/001-Puss-Gets-the-Boot.avi",
  });

  useEffect(() => {
    // Fetch video data from server API endpoint
    fetch("http://localhost:3000/api/play/tom-jerry/001-Puss-Gets-the-Boot.avi") // Replace `/api/videos` with your actual API endpoint
      .then((response) => response.json())
      .then((data) => setVideos(data))
      .catch((error) => console.error(error));
  }, []); // Run effect only once on component mount

  const handleVideoClick = (video) => {
    setSelectedVideo(video);
  };

  return (
    <div className="App">
      <VideoList videos={videos} onVideoClick={handleVideoClick} />
      {selectedVideo && <VideoPlayer videoId={selectedVideo.url} />}
      <div>
        <h2>Copyright by Shipsar Developers</h2>
      </div>
    </div>
  );
};

export default App;
