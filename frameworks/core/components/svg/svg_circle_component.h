/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_SVG_SVG_CIRCLE_COMPONENT_H
#define FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_SVG_SVG_CIRCLE_COMPONENT_H

#include "frameworks/core/components/svg/svg_sharp.h"
#include "frameworks/core/pipeline/base/component_group.h"

namespace OHOS::Ace {

class SvgCircleComponent : public ComponentGroup, public SvgSharp {
    DECLARE_ACE_TYPE(SvgCircleComponent, ComponentGroup, SvgSharp);

public:
    SvgCircleComponent() = default;
    explicit SvgCircleComponent(const std::list<RefPtr<Component>>& children) : ComponentGroup(children) {};
    ~SvgCircleComponent() override = default;

    RefPtr<RenderNode> CreateRenderNode() override;

    RefPtr<Element> CreateElement() override;

    void SetCx(const Dimension& cx)
    {
        cx_ = cx;
    }

    const Dimension& GetCx() const
    {
        return cx_;
    }

    void SetCy(const Dimension& cy)
    {
        cy_ = cy;
    }

    const Dimension& GetCy() const
    {
        return cy_;
    }

    void SetR(const Dimension& r)
    {
        r_ = r;
    }

    const Dimension& GetR() const
    {
        return r_;
    }

private:
    Dimension cx_;
    Dimension cy_;
    Dimension r_;
};

} // namespace OHOS::Ace

#endif // FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_SVG_SVG_CIRCLE_COMPONENT_H