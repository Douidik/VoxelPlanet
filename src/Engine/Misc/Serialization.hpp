#ifndef VOXENG_SERIALIZATION_HPP
#define VOXENG_SERIALIZATION_HPP

#include <cereal/archives/json.hpp>

namespace VoxelEngine
{

enum class SerializationCategory
{
    Core,
    Renderer,
    Keybindings
};

enum class SerializationAction
{
    Load,
    Save
};

template <class InputArchive, class OutputArchive>
class Serializer
{
public:
    Serializer(fs::path path)
        : m_InputStream(path)
        , m_OutputStream(path)
    {
        VOXENG_ASSERT(m_InputStream.good() && m_OutputStream.good(), "Failed to open configuration file: {}", path);
        m_InputArchive = std::make_unique<InputArchive>(m_InputStream);
        m_OutputArchive = std::make_unique<OutputArchive>(m_OutputStream);
    }

    template <class T>
    void Load(T *serializable)
    {
        m_InputArchive(serializable->GetSerializationKey(), *serializable);
    }

    template <class T>
    void Save(T *serializable)
    {
        m_OutputArchive(serializable->GetSerializationKey(), *serializable);
    }

private:
    std::ifstream m_InputStream;
    std::ofstream m_OutputStream;

    std::unique_ptr<InputArchive> m_InputArchive;
    std::unique_ptr<OutputArchive> m_OutputArchive;
};

using DefaultSerializer = Serializer<cereal::JSONInputArchive, cereal::JSONOutputArchive>;
using BinarySerializer = Serializer<cereal::BinaryInputArchive, cereal::BinaryOutputArchive>;

static std::unordered_map<SerializationCategory, DefaultSerializer> s_Serializers = {
    {SerializationCategory::Core, DefaultSerializer("res/EngineSettings.json")},
    {SerializationCategory::Renderer, DefaultSerializer("res/VideoSettings.json")},
    {SerializationCategory::Keybindings, DefaultSerializer("res/Keybindings.json")}};

template <class T, SerializationCategory Category>
class Serializable
{
public:
    Serializable(const std::string &serializationKey = "")
        : m_SerializationKey(serializationKey)
    {
        Serialize(SerializationAction::Load);
    }

    ~Serializable()
    {
        Serialize(SerializationAction::Save);
    }

    inline const std::string &GetSerializationKey() const
    {
        return m_SerializationKey;
    }

private:
    void Serialize(SerializationAction action)
    {
        VOXENG_ASSERT(!m_SerializationKey.empty(), "No specified key for the serialized instance");

        T *serializable = static_cast<T *>(this);
        try
        {
            if (action == SerializationAction::Load)
                s_Serializers.at(Category).Load(serializable);
            else
                s_Serializers.at(Category).Save(serializable);
        }
        catch (const std::out_of_range &)
        {
            VOXENG_ERROR("Unregistered serialization category");
        }
    }

    // Name used during the serialization
    std::string m_SerializationKey;
};

} // namespace VoxelEngine

#define SERIALIZABLE(Name, Category)                                                                                                                           \
    Name:                                                                                                                                                      \
    Serializable<Name, ::VoxelEngine::SerializationCategory::Category>

#endif
