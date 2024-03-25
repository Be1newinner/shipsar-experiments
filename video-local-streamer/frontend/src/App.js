import React, { useState, useEffect } from "react";
import VideoPlayer from "./VideoPlayer";
import VideoList from "./VideoList";

const App = () => {
  const [videos, setVideos] = useState([]);
  const [selectedVideo, setSelectedVideo] = useState(null);

  useEffect(() => {
    // Fetch video data from server API endpoint
    fetch("/api/videoslist") // Replace `/api/videos` with your actual API endpoint
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
      {selectedVideo && <VideoPlayer videoSrc={selectedVideo.url} />}
      <div>
        <h2>Copyright by Shipsar Developers</h2>
      </div>
    </div>
  );
};

export default App;
