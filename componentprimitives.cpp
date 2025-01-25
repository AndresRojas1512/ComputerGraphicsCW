#include "componentprimitives.hpp"

std::ostream& operator<<(std::ostream& os, const ParallelepipedConfig& p)
{
    return os << "Parallelepiped[x=" << p.x << ", y=" << p.y << ", z=" << p.z
              << ", width=" << p.width << ", height=" << p.height << ", depth=" << p.depth << "]";
}

std::ostream& operator<<(std::ostream& os, const FrameConfig& f)
{
    return os << "Frame[x=" << f.x << ", y=" << f.y << ", z=" << f.z
              << ", width=" << f.width << ", height=" << f.height << ", depth=" << f.depth
              << ", topFrameWidth=" << f.topFrameWidth << ", bottomFrameWidth=" << f.bottomFrameWidth
              << ", leftFrameWidth=" << f.leftFrameWidth << ", rightFrameWidth=" << f.rightFrameWidth << "]";
}

std::ostream& operator<<(std::ostream& os, const ComponentConfig& config)
{
    os << "ComponentConfig with " << config.parallelepipeds.size() << " parallelepipeds and "
       << config.frames.size() << " frames.\n";
    for (const auto& p : config.parallelepipeds)
    {
        os << p << std::endl;
    }
    for (const auto& f : config.frames)
    {
        os << f << std::endl;
    }
    return os;
}
