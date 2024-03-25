import React, { useState, useEffect } from "react";

const VideoPlayer = ({ videoSrc }) => {
  const [isPlaying, setIsPlaying] = useState(false);

  useEffect(() => {
    // Handle video playback state and other player controls here
  }, [videoSrc]); // Re-run effect when videoSrc changes

  const togglePlay = () => {
    setIsPlaying(!isPlaying);
  };

  return (
    <div className="video-player">
      <video src={videoSrc} controls autoPlay={isPlaying} />
      <button onClick={togglePlay}>{isPlaying ? "Pause" : "Play"}</button>
    </div>
  );
};

export default VideoPlayer;
